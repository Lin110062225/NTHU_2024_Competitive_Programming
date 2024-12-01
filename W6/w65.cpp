#include <bits/stdc++.h>
using namespace std;

// int bd[9];
vector<int> bd(9);
int num = 0;

int get_score(vector<int> &x) {
    int sum = 0;
    for (int i = 0; i < 9; i++) {
        int d = abs(i - x[i]);
        sum += (d/3 + d%3);
    }
    return sum;
}

void bfs() {
    queue<tuple<vector<int>, int, int>> q;
    int score = get_score(bd);
    q.push(make_tuple(bd, score, 0));

    while (!q.empty()) {
        vector<int> cur(9);
        cur = get<0>(q.front());
        int score = get<1>(q.front());
        int steps = get<2>(q.front());

        if (score == 0) {
            cout << steps << endl;
            break;
        }
        q.pop();

        for (int i = 0; i < 9; i++) {
            if ((i+1) % 3 && (cur[i] != i || cur[i+1] != i+1)) {
                swap(cur[i], cur[i+1]);
                int new_score = get_score(cur);
                if (new_score <= score) {
                    q.push(make_tuple(cur, new_score, steps+1));
                }
                swap(cur[i], cur[i+1]);
            }
            if (i < 6 && (cur[i] != i || cur[i+3] != i+3)) {
                swap(cur[i], cur[i+3]);
                int new_score = get_score(cur);
                if (new_score <= score) {
                    q.push(make_tuple(cur, new_score, steps+1));
                }
                swap(cur[i], cur[i+3]);
            }
        }
    }
}

int main() {
    for (int i = 0; i < 9; i++) {
        cin >> bd[i];
        bd[i]--;
    }
    bfs();
}

/*
#include <bits/stdc++.h>
using namespace std;

const int target[9] = {0,1,2,3,4,5,6,7,8};

// Convert grid state to a single integer for efficient storage
int encode(const vector<int>& state) {
    int code = 0;
    for(int i = 0; i < 9; i++) {
        code = code * 9 + state[i];
    }
    return code;
}

// More efficient Manhattan distance calculation
int get_manhattan_distance(const vector<int>& state) {
    int dist = 0;
    for(int i = 0; i < 9; i++) {
        if(state[i] != i) {
            int curr_row = i / 3, curr_col = i % 3;
            int target_row = state[i] / 3, target_col = state[i] % 3;
            dist += abs(curr_row - target_row) + abs(curr_col - target_col);
        }
    }
    return dist;
}

int solve(vector<int>& start) {
    queue<pair<vector<int>, int>> q;
    unordered_set<int> visited;
    
    q.push({start, 0});
    visited.insert(encode(start));
    
    while(!q.empty()) {
        vector<int> curr = q.front().first;
        int moves = q.front().second;
        q.pop();
        
        if(curr == vector<int>(target, target + 9)) {
            return moves;
        }
        
        // Try all possible moves
        for(int i = 0; i < 9; i++) {
            // Horizontal swaps
            if((i % 3) < 2) {
                vector<int> next = curr;
                swap(next[i], next[i + 1]);
                int encoded = encode(next);
                if(visited.find(encoded) == visited.end()) {
                    visited.insert(encoded);
                    q.push({next, moves + 1});
                }
            }
            
            // Vertical swaps
            if(i < 6) {
                vector<int> next = curr;
                swap(next[i], next[i + 3]);
                int encoded = encode(next);
                if(visited.find(encoded) == visited.end()) {
                    visited.insert(encoded);
                    q.push({next, moves + 1});
                }
            }
        }
    }
    return -1;
}

int main() {
    vector<int> grid(9);
    for(int i = 0; i < 9; i++) {
        cin >> grid[i];
        grid[i]--; // Convert to 0-based indexing
    }
    
    cout << solve(grid) << endl;
    return 0;
}
*/