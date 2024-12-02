#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
int cnt[100001];
vector<pair<ll, ll>> f;

bool less_than(ll mid) {
    for (int i = 0; i <= n; i++) cnt[i] = 0;

    for (int i = 0; i < n; i++) {
        ll to_find = (mid - f[i].second) / f[i].first;
        if (to_find < 1) return false;
        if (to_find > n) to_find = n;
        cnt[to_find]++;
    }

    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += cnt[i];
        if (sum > i) return false;
    }

    return true;
}

int main() {
    cin >> n;
    f.assign(n, make_pair(0, 0));

    for (int i = 0; i < n; i++) {
        cin >> f[i].first >> f[i].second;
    }

    ll L = 0, R = 1e15;
    while (L < R) {
        ll mid = L + (R - L) / 2;
        if (less_than(mid)) R = mid;
        else L = mid + 1;
    }
    
    cout << R << endl;
}