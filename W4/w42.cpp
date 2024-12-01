#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n, x;
    cin >> n >> x;

    map<ll, ll> mp;
    mp[0] = 1;
    ll ans = 0;
    ll cum = 0;

    for (int i = 0; i < n; i++) {
        ll cur;
        cin >> cur;
        cum += cur;
        ans += mp[cum - x];
        mp[cum]++;
    }
    
    cout << ans << endl;
}