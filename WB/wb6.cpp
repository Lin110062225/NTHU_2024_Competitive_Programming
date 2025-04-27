#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<ll> pre(n+1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        pre[i] = pre[i-1] + x;
    }

    vector<vector<ll>> dp(n+1, vector<ll>(n+1));
    for (int i = 1; i < n; i++) {  // length of sublist
        for (int j = 1; j+i <= n; j++) {
            dp[j][j+i] = LLONG_MAX;
            for (int k = j; k < j+i; k++) {
                dp[j][j+i] = min(dp[j][j+i], dp[j][k] + dp[k+1][j+i] + pre[j+i] - pre[j-1]);
            }
        }
    }
    cout << dp[1][n] << endl;  // from the first slime to n
}