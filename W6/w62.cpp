/*
#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<int> jug;

void full(int i) {
    //
}

void empty(int i) {
    //
}

void pour(int a, int b) {
    //
}

void solve() {
    //
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        jug.emplace_back(a);
    }
    cin >> q;

    solve();
}
*/

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

// State class to represent the amount of water in each jug
class State {
public:
    vector<int> jugs;
    int steps;
    
    State(vector<int> j, int s) : jugs(j), steps(s) {}
    
    // Generate hash for state to use in visited set
    string getHash() const {
        string hash = "";
        for (int x : jugs) {
            hash += to_string(x) + ",";
        }
        return hash;
    }
};

int solve(vector<int>& capacity, int Q) {
    int N = capacity.size();
    
    // Initialize starting state with empty jugs
    vector<int> start(N, 0);
    State initial(start, 0);
    
    // BFS queue and visited set
    queue<State> q;
    unordered_set<string> visited;
    
    q.push(initial);
    visited.insert(initial.getHash());
    
    while (!q.empty()) {
        State curr = q.front();
        q.pop();
        
        // Check if target amount Q is achieved in any jug
        for (int amount : curr.jugs) {
            if (amount == Q) return curr.steps;
        }
        
        // Try all possible operations
        
        // 1. Fill a jug to full
        for (int i = 0; i < N; i++) {
            if (curr.jugs[i] < capacity[i]) {
                vector<int> next = curr.jugs;
                next[i] = capacity[i];
                
                State nextState(next, curr.steps + 1);
                string hash = nextState.getHash();
                
                if (visited.find(hash) == visited.end()) {
                    visited.insert(hash);
                    q.push(nextState);
                }
            }
        }
        
        // 2. Empty a jug
        for (int i = 0; i < N; i++) {
            if (curr.jugs[i] > 0) {
                vector<int> next = curr.jugs;
                next[i] = 0;
                
                State nextState(next, curr.steps + 1);
                string hash = nextState.getHash();
                
                if (visited.find(hash) == visited.end()) {
                    visited.insert(hash);
                    q.push(nextState);
                }
            }
        }
        
        // 3. Transfer water between jugs
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i != j && curr.jugs[i] > 0 && curr.jugs[j] < capacity[j]) {
                    vector<int> next = curr.jugs;
                    
                    // Calculate how much water can be transferred
                    int transfer = min(curr.jugs[i], capacity[j] - curr.jugs[j]);
                    next[i] -= transfer;
                    next[j] += transfer;
                    
                    State nextState(next, curr.steps + 1);
                    string hash = nextState.getHash();
                    
                    if (visited.find(hash) == visited.end()) {
                        visited.insert(hash);
                        q.push(nextState);
                    }
                }
            }
        }
    }
    
    return -1;  // Impossible to achieve target amount
}

int main() {
    int N;
    cin >> N;
    
    vector<int> capacity(N);
    for (int i = 0; i < N; i++) {
        cin >> capacity[i];
    }
    
    int Q;
    cin >> Q;
    
    cout << solve(capacity, Q) << endl;
    
    return 0;
}