#include <bits/stdc++.h>
using namespace std;

int n, m;
bool many;
vector<vector<int>> graph;
vector<int> one;  // {0, 1, 2}

void dfs(int cur, int color) {
    for (auto t: graph[cur]) {
        if (!one[t]) {  // if one[t] != 0
            one[t] = color;
            dfs(t, (color % 2) + 1);  // change color
        }
        else if (color != one[t]){  // illegal cycle occurs
            many = true;
        }
    }
}

int main() {
    cin >> n >> m;
    graph.assign(n, vector<int>());
    one.assign(n, 0);  // 0: haven't be visited

    while (m--) {
        int p1, p2;
        cin >> p1 >> p2;
        graph[p1-1].emplace_back(p2-1);
        graph[p2-1].emplace_back(p1-1);
    }

    many = false;
    for (int i = 0; i < n; i++) {
        if (one[i]) continue;
        one[i] = 1;
        dfs(i, 2);
        if (many) {
            cout << "MANY" << endl;
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << one[i] << " \n"[i == n-1];
    }
}