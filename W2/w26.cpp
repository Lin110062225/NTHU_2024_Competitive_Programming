// sudoku
#include <bits/stdc++.h>
using namespace std;

string board;
vector<int> blocks(9, 0);
vector<int> rows(9, 0);
vector<int> cols(9, 0);
vector<int> points;
deque<int> ans;

bool dfs(int i) {
    if (i == points.size()) return true;

    int r = points[i] / 9;
    int c = points[i] % 9;

    for (int k = 1; k < 512; k <<= 1) {

        if (k & ~(rows[r] | cols[c] | blocks[(r/3)*3 + (c/3)])) {

            ans.emplace_back(__lg(k) + 1);
            rows[r] ^= k;
            cols[c] ^= k;
            blocks[(r/3)*3 + (c/3)] ^= k;

            if (dfs(i + 1)) return true;

            ans.pop_back();
            rows[r] ^= k;
            cols[c] ^= k;
            blocks[(r/3)*3 + (c/3)] ^= k;
        }
    }
    return false;
}

int main() {
    while (cin >> board) {
        if (board == "end") break;
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i*9 + j] != '.') {
                    int op = (1 << (board[i*9 + j] - '1'));
                    blocks[(i/3)*3 + (j/3)] |= op;
                    rows[i] |= op;
                    cols[j] |= op;
                }
                else {
                    // position of '.'
                    points.emplace_back(i*9 + j);
                }
            }
        }

        if (!dfs(0)) {
            cout << "No solution.";
        }
        else {
            // handle invalid input
            bool valid = true;
            for (int i = 0; i < 9; i++) {
                // check board is filled
                if (!((blocks[i] & rows[i] & cols[i]) == (1 << 9) - 1)) {
                    valid = false;
                }
                blocks[i] = rows[i] = cols[i] = 0;
            }
            if (valid) {
                for (int i = 0; i < 81; i++) {
                    if (board[i] == '.') {
                        board[i] = ans.front() + '0';
                        ans.pop_front();
                    }
                    cout << board[i];
                }
            }
            else {
                ans.clear();
                cout << "No solution.";
            }
        }
        cout << endl;
        points.clear();
    } 
}

// test cases
/*
5.73284911324697..4895712638437951267956123842168.35793519876426281549379742.6815
8.762513.5123.7689..6.8925767391482.2548763.11895324.69254687134..751962.612935.8
end
*/