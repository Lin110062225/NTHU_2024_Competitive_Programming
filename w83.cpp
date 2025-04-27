#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
vector<int> sz;
vector<ll> ans;
vector<vector<int>> nodes;

void dfs1(int cur, int parent, ll d) {
    // find the answer of 0 first
    ans[0] += d;
    // count how many children nodes[cur] has, including itself
    sz[cur] = 1;

    for (auto t: nodes[cur]) {
        if (t != parent) {
            dfs1(t, cur, d+1);
            sz[cur] += sz[t];
        }
    }
}

void dfs2(int cur, int parent) {
    for (auto t: nodes[cur]) {
        if (t != parent) {
            ans[t] = ans[cur] + n - 2*sz[t];
            dfs2(t, cur);
        }
    }
}

int main() {
    cin >> n;
    sz.assign(n, 0);
    ans.assign(n, 0);
    nodes.assign(n, vector<int>());
    
    for (int i = 0; i < n-1; i++) {
        int p1, p2;
        cin >> p1 >> p2;
        nodes[p1-1].emplace_back(p2-1);
        nodes[p2-1].emplace_back(p1-1);
    }

    dfs1(0, -1, 0);
    dfs2(0, -1);

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n-1];
    }
}