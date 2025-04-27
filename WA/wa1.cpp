#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m, k;
const int mod = 1e9 + 7;
vector<vector<ll>> ans;
vector<vector<ll>> edges;

vector<vector<ll>> mul(vector<vector<ll>> &a, vector<vector<ll>> &b) {
    vector<vector<ll>> res(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % mod;
            }
        }
    }
    return res;
}

int main() {
    cin >> n >> m >> k;
    ans.assign(n, vector<ll>(n, 0));
    edges.assign(n, vector<ll>(n, 0));

    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        edges[s-1][e-1]++;
    }
    for (int i = 0; i < n; i++) {
        ans[i][i] = 1;
    }

    while (k) {
        if (k & 1) {
            ans = mul(ans, edges);
        }
        k >>= 1;
        edges = mul(edges, edges);
    }
    
    cout << ans[0][n-1] << endl;
}