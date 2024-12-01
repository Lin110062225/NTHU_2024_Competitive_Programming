#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll p = 1e9 + 7;

ll power(ll a, ll b, ll md) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % md;
        b >>= 1;
        a = a * a % md;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        ll a, b, c;
        cin >> a >> b >> c;
        cout << power(a, power(b, c, p-1), p) << endl;
    }
}