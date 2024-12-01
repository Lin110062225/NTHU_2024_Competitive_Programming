#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 1e9 + 7;

int main() {
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll i = 1; i*i <= n; i++) {
        ll x = n / i;
        // 先加 i 為除數的部分
        ans = (ans + i * (x - i + 1)) % mod;
        // 再加除 i 得到的商的部分
        ans = (ans + (((x % mod) * ((x + 1) % mod) / 2 % mod) - (i * (i + 1) / 2 % mod) + mod) % mod) % mod;
    }
    cout << ans << endl;
}

/*
(a + b) % mod = (a % mod + b % mod) % mod
(a - b) % mod = (a % mod - b % mod + mod) % mod
*/