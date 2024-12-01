#include <bits/stdc++.h>
using namespace std;

int n, m;
int num = 0;
char board[1001][1001];

void bfs(int row, int col) {
    queue<pair<int, int>> q;
    q.push(make_pair(row, col));

    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();

        if (x > 0 && board[x-1][y] == '.') {
            board[x-1][y] = '#';
            q.push(make_pair(x-1, y));
        }
        if (x < n-1 && board[x+1][y] == '.') {
            board[x+1][y] = '#';
            q.push(make_pair(x+1, y));
        }
        if (y > 0 && board[x][y-1] == '.') {
            board[x][y-1] = '#';
            q.push(make_pair(x, y-1));
        }
        if (y < m-1 && board[x][y+1] == '.') {
            board[x][y+1] = '#';
            q.push(make_pair(x, y+1));
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
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == '.') {
                bfs(i, j);
                num++;
            }
        }
    }
    cout << num << endl;
}