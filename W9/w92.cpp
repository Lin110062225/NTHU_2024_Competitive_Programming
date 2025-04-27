#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    // vector<vector<int>> path(n, vector<int>(n, INT_MAX/2));
    vector<vector<pii>> path(n);

    for (int i = 0; i < m; i++) {
        int b, e, w;
        cin >> b >> e >> w;
        // path[b-1][e-1] = min(path[b-1][e-1], w);
        path[b-1].emplace_back(pii(e-1, w));
    }

    vector<ll> d(n, LLONG_MAX/2);
    d[0] = 0;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push(make_pair(d[0], 0));

    while (pq.size()) {
        ll dis = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dis != d[cur]) continue;

        // for (int i = 0; i < path[cur].size(); i++) {
        //     if (d[i] > d[cur] + path[cur][i]) {
        //         d[i] = d[cur] + path[cur][i];
        //         pq.push(make_pair(d[i], i));
        //     }
        // }

        for (int i = 0; i < path[cur].size(); i++) {
            if (d[path[cur][i].first] > d[cur] + path[cur][i].second) {
                d[path[cur][i].first] = d[cur] + path[cur][i].second;
                pq.push(make_pair(d[path[cur][i].first], path[cur][i].first));
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << d[i] << " \n"[i == n-1];
    }
}

// original solution will cause memory limit exceed