#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> nodes(n, vector<int>());
    vector<int> in(n, 0);

    for (int i = 0; i < m; i++) {
        int p1, p2;
        cin >> p1 >> p2;
        nodes[p2-1].emplace_back(p1-1);  // reverse the graph
        in[p1-1]++;
    }

    queue<int> q;
    vector<bitset<50001>> dp(n);

    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;  // node itself
        if (in[i] == 0) q.push(i);  // end point of original graph
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto t: nodes[cur]) {
            dp[t] |= dp[cur];  // ex: 00...110 | 00...011 = 00...111
            in[t]--;
            if (in[t] == 0) q.push(t);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << dp[i].count() << " \n"[i == n-1];  // (how many '1' in dp[i]) == (num of reachable nodes)
    }
}