#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<pii, int>> p(n);  // ((start, end), money)
    vector<int> v;  // timeline

    for (int i = 0; i < n; i++) {
        cin >> p[i].first.first >> p[i].first.second >> p[i].second;
        v.emplace_back(p[i].first.first);
        v.emplace_back(p[i].first.second);
    }

    sort(p.begin(), p.end());
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    vector<ll> dp(v.size() + 1);
    ll ans = 0;

    for (int i = 0, j = 0; i < n; i++) {
        int start = lower_bound(v.begin(), v.end(), p[i].first.first) - v.begin();
        int k = lower_bound(v.begin(), v.end(), p[i].first.second) - v.begin() + 1;

        while (j < start) j++, dp[j] = max(dp[j], dp[j-1]);

        dp[k] = max(dp[k], dp[start] + p[i].second);
        ans = max(ans, dp[k]);
    }
    
    cout << ans << endl;
}