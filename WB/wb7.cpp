#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<int>> e;
vector<vector<ll>> dp;

const int mod = 1e9 + 7;

int dfs(int cur, int parent, int color) {
    if (dp[color][cur]) {
        return dp[color][cur];
    }
    dp[color][cur] = 1;
    for (auto t: e[cur]) {
        if (t != parent) {
            int w, b = 0;
            w = dfs(t, cur, 0);
            if (!color) b = dfs(t, cur, 1);
            dp[color][cur] = dp[color][cur] * (w+b) % mod;
        }
    }
    return dp[color][cur];
}

int main() {
    int n;
    cin >> n;

    e.assign(n, vector<int>());
    dp.assign(2, vector<ll>(n));  // 0: white, 1: black

    for (int i = 0; i < n-1; i++) {
        int p1, p2;
        cin >> p1 >> p2;
        e[p1-1].emplace_back(p2-1);
        e[p2-1].emplace_back(p1-1);
    }

    cout << (dfs(0, -1, 0) + dfs(0, -1, 1)) % mod << endl;  // 0 is white + 0 is black
}