#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

bool cmp(pii &a, pii &b) {
    return a.second <= b.second;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<pii> mv(n);
    for (int i = 0; i < n; i++) {
        cin >> mv[i].first >> mv[i].second;
    }
    sort(mv.begin(), mv.end(), cmp);

    multiset<int> s;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        // I don't know why we can't use greater<int>() in lower_bound, so we make them negative here
        // and we need to use built in lower_bound function or the code will get TLE
        // ex: lower_bound(s.begin(), s.end(), -mv[i].first) will get TLE
        auto it = s.lower_bound(-mv[i].first);  
        if (it == s.end() && s.size() >= k) continue;
        if (it != s.end()) s.erase(it);
        s.insert(-mv[i].second);
        ans++;
    }

    cout << ans << endl;
}