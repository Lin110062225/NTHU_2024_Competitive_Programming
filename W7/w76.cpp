#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 1e9 + 7;
ll A[1000001], B[1000001];

ll power(ll a, ll b) {
    ll ans = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1) {
            ans = ans * a % mod;
        }
    }
    return ans;
}

void set_up() {
    A[0] = 1;
    for (int i = 1; i < 1000001; i++) {
        A[i] = A[i-1] * i % mod;
    }
    B[1000000] = power(A[1000000], mod-2);
    for (int i = 1000000; i > 0; i--) {
        B[i-1] = B[i] * i % mod;
    }
}

int main() {
    set_up();
    int n;
    cin >> n;
    int x, y;
    while (n--) {
        cin >> x >> y;
        cout << A[x] * B[y] % mod * B[x-y] % mod << endl;
    }
}