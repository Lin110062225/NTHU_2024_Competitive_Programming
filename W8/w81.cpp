#include <bits/stdc++.h>
using namespace std;

int n;
int ans = 0;
vector<vector<int>> tree;
vector<int> d1, d2;

void dfs(int cur, int parent) {
    for (auto t: tree[cur]) {
        if (t == parent) continue;
        dfs(t, cur);
        if (d1[cur] < d1[t] + 1) {
            d2[cur] = d1[cur];
            d1[cur] = d1[t] + 1;
        }
        else {
            d2[cur] = max(d2[cur], d1[t] + 1);
        }
    }
    ans = max(ans, d1[cur] + d2[cur]);
}

int main() {
    cin >> n;
    tree.assign(n+1, vector<int>());
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].emplace_back(b);
        tree[b].emplace_back(a);
    }
    d1.assign(n+1, 0);
    d2.assign(n+1, 0);
    dfs(1, -1);
    cout << ans << endl;
}
