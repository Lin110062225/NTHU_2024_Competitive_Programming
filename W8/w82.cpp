#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> edges;
vector<vector<int>> d;

void dfs(int cur, int len, int parent, int idx) {
    for (int i = 0; i < edges[cur].size(); i++) {
        if (edges[cur][i] != parent) {
            dfs(edges[cur][i], len+1, cur, idx);
            d[idx][edges[cur][i]] = len;
        }
    }
}

int main() {
    cin >> n;
    edges.assign(n, vector<int>());
    d.assign(3, vector<int>(n, 0));  // 0: len from start to each nodes, 1: from n1, 2: from n2
    int start = 0;

    for (int i = 0; i < n-1; i++) {
        int p1, p2;
        cin >> p1 >> p2;
        edges[p1-1].emplace_back(p2-1);
        edges[p2-1].emplace_back(p1-1);
        if (i == 0) start = p1-1;
    }

    dfs(start, 1, -1, 0);
    int n1 = distance(d[0].begin(), max_element(d[0].begin(), d[0].end()));
    dfs(n1, 1, -1, 1);
    int n2 = distance(d[1].begin(), max_element(d[1].begin(), d[1].end()));
    dfs(n2, 1, -1, 2);
    
    for (int i = 0; i < n; i++) {
        cout << max(d[1][i], d[2][i]) << " \n"[i == n-1];
    }
}