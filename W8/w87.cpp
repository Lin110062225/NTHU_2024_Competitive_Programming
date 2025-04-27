#include <bits/stdc++.h>
using namespace std;

int n;
int ans;
vector<int> sz;
vector<vector<int>> nodes;

void dfs(int cur, int parent) {
    int max_son = 0;
    for (auto t: nodes[cur]) {
        if (t != parent) {
            dfs(t, cur);
            sz[cur] += sz[t];
            max_son = max(max_son, sz[t]);
        }
    }
    max_son = max(max_son, n-sz[cur]);
    if (max_son <= n/2) ans = cur;
}

int main() {
    cin >> n;
    sz.assign(n, 1);
    nodes.assign(n, vector<int>());
    for (int i = 0; i < n-1; i++) {
        int p1, p2;
        cin >> p1 >> p2;
        nodes[p1-1].emplace_back(p2-1);
        nodes[p2-1].emplace_back(p1-1);
    }
    dfs(0, -1);
    cout << ans+1 << endl;  // to make (0 ~ n-1) => (1 ~ n), we +1
}