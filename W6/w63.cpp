#include <bits/stdc++.h>
using namespace std;

int n, m;
int ans = INT_MAX;
int start;

char board[1001][1001];
char pre[1001][1001];
int cnt[1001][1001];

// trace path
void dfs(int r, int c) {
    if (!pre[r][c]) return;

    if (pre[r][c] == 'D') dfs(r - 1, c);
    else if (pre[r][c] == 'U') dfs(r + 1, c);
    else if (pre[r][c] == 'R') dfs(r, c - 1);
    else dfs(r, c + 1);

    cout << pre[r][c];
}

void bfs() {
    queue<int> q;  // only need current position
    q.push(start);
    cnt[start / m][start % m] = 0;
    
    while (!q.empty()) {
        int cur = q.front();
        int row = cur / m;
        int col = cur % m;

        if (board[row][col] == 'B') {
            cout << "YES" << endl;

            ans = cnt[row][col];
            cout << ans << endl;

            dfs(row, col);
            cout << endl;
            break;
        }
        q.pop();

        if (row > 0 && board[row - 1][col] != '#' && cnt[row - 1][col] < 0) {  // use cnt instead of visited to reduce time
            cnt[row - 1][col] = cnt[row][col] + 1;  // steps += 1
            pre[row - 1][col] = 'U';  // record path
            q.push(cur - m);
        }
        if (row < n-1 && board[row + 1][col] != '#' && cnt[row + 1][col] < 0) {
            cnt[row + 1][col] = cnt[row][col] + 1;
            pre[row + 1][col] = 'D';
            q.push(cur + m);
        }
        if (col > 0 && board[row][col - 1] != '#' && cnt[row][col - 1] < 0) {
            cnt[row][col - 1] = cnt[row][col] + 1;
            pre[row][col - 1] = 'L';
            q.push(cur - 1);
        }
        if (col < m-1 && board[row][col + 1] != '#' && cnt[row][col + 1] < 0) {
            cnt[row][col + 1] = cnt[row][col] + 1;
            pre[row][col + 1] = 'R';
            q.push(cur + 1);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            board[i][j] = s[j];
            if (s[j] == 'A') start = i*m + j;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cnt[i][j] = -1;
        }
    }

    bfs();  // don't use dfs for finding shortest path

    if (ans == INT_MAX) cout << "NO" << endl;
}