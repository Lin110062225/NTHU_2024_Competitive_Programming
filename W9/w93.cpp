#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<ll>> roads(n, vector<ll>(n, LLONG_MAX/2));  // don't use INT_MAX, too small

    for (int i = 0; i < n; i++) {  // remember !!
        roads[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        roads[a-1][b-1] = roads[b-1][a-1] = min((ll)c, roads[a-1][b-1]);  // remember too !!
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                roads[i][j] = min(roads[i][j], roads[i][k] + roads[k][j]);
            }
        }
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        if (roads[a-1][b-1] == LLONG_MAX/2) cout << -1 << endl;
        else cout << roads[a-1][b-1] << endl;
    }
}