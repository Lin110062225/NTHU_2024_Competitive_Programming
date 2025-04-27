#include <bits/stdc++.h>
#define ll long long
using namespace std;

// It is not always the best solution to pick the heaviest person first,
// then start picking people from the lightest.
// It doesn't work when n = 5, x = 10, wi = [7, 4, 4, 3, 2].
// The best solution is 2 times ([7, 3], [4, 4, 2]),
// but we will get 3 times ([7, 2], [4, 3], [4]) if we take the approach above.
// So these problems have to use DP.

int main() {
    int n, x;
    cin >> n >> x;
    // dp is the minimum number of rides, w is the current weight on elevator
    vector<int> p(n), dp(1<<n, INT_MAX), w(1<<n, INT_MAX);

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    dp[0] = 1;  // at least one ride
    w[0] = 0;

    for (ll i = 1; i < (1<<n); i++) {
        for (int j = 0; j < n; j++) {
            if ((i>>j) & 1) {
                // subset without j
                ll s = i & ~(1<<j);
                if (w[s] + p[j] > x) {
                    if (dp[s] + 1 < dp[i] || dp[s] + 1 == dp[i] && w[i] > p[j]) {
                        dp[i] = dp[s] + 1;
                        w[i] = p[j];
                    }
                }
                else {
                    if (dp[s] < dp[i] || dp[s] == dp[i] && w[s] + p[j] < w[i]) {
                        dp[i] = dp[s];
                        w[i] = w[s] + p[j];
                    }
                }
            }
        }
    }

    cout << dp[(1<<n) - 1] << endl;
}