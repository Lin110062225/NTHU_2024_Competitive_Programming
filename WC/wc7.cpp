#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;

int lowbit(int x) {return x & -x;}

class BIT {
private:
    int n;
    vector<ll> bit;

public:
    BIT(int n): n(n), bit(n+1) {}

    void update(int x, ll v) {
        for (; x <= n; x += lowbit(x)) bit[x] = max(bit[x], v);
        // for (int i = 0; i <= n; i++) cout << bit[i] << " \n"[i == n];
        // cout << endl;
    }

    ll query(int x) {
        ll res = 0;
        for (; x; x -= lowbit(x)) {
            // cout << "bit[" << x << "]: " << bit[x] << endl;
            res = max(bit[x], res);
        }
        // cout << "max: " << res << endl;
        return res;
    }
};

// use BIT to implement dp

int main() {
    int n;
    cin >> n;

    vector<pii> f(n);  // (height, beauty)
    for (int i = 0; i < n; i++) cin >> f[i].first;
    for (int i = 0; i < n; i++) cin >> f[i].second;

    BIT b(n+1);
    for (int i = 0; i < n; i++) {
        ll sum = b.query(f[i].first - 1) + f[i].second;
        b.update(f[i].first, sum);
    }

    cout << b.query(n+1) << endl;
}