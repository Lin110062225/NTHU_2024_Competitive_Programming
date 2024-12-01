// https://cses.fi/problemset/task/1624/
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

vector<string> board(8);
ull llb = 0;
ull ONE = 1;
int ans = 0;

void show() {
    for (int i = 7; i >= 0; i--) {
        cout << bitset<8>((llb >> (i*8)) % 256) << endl;
    }
    cout << endl;
}

bool check(int row, int col) {
    ull l, m, r;
    ull mix = 0;
    ull mask = ((ONE << 8) - 1);
    l = m = r = (128 >> col);
    for (int i = row; i < 7; i++) {
        l <<= 1;
        r >>= 1;
        mix = l | m | r;
        if (((llb >> ((6 - i)*8)) & mask) & mix) {
            return false;
        }
    }
    return true;
}

void dfs(int row) {
    if (row < 0) {
        ans++;
        return;
    }
    for (int i = 7; i >= 0; i--) {
        if (board[row][i] == '.') {
            if (check(row, i)) {
                ull tmp = (ONE << (63 - (row*8 + i)));
                llb ^= tmp;
                dfs(row - 1);
                llb ^= tmp;
            }
        }
    }
}

int main() {
    for(int i = 0; i < 8; i++) cin >> board[i];
    // start from bottom right
    dfs(7);
    cout << ans << endl;
}