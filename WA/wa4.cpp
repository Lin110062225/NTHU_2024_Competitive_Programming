#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int md = 1e9 + 7;

// see 0/1 knapsack problem

int main() {
    int n;
    cin >> n;
    int sum = n * (n+1) / 2;
    if (sum % 2) {
        cout << 0 << endl;  // answer is zero when sum is odd
        return 0;
    }
    sum /= 2;  // two part
    vector<ll> dp(sum + 1);
    dp[0] = 1;  // remember
    for (int i = 1; i <= n; i++) {
        for (int j = sum; j-i >= 0; j--) {
            dp[j] = (dp[j] + dp[j-i]) % md;  // whether take i or not
        }
    }
    cout << dp[sum] * (ll)(5e8 + 4) % md << endl;  // devided by 2
}