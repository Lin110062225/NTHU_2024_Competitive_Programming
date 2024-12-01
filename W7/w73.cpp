#include <bits/stdc++.h>
#define ll long long
using namespace std;

int f[1000001];
ll dp[1000001];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        f[x]++;  // frequency count
    }

    for (int i = 1000000; i >= 1; i--) {  // greatest common divisor, search from high to low
        ll num = 0, r = 0;
        for (int j = i; j < 1000001; j += i) {
            num += f[j];
            r += dp[j];
            /*
            ex: Let x = {3, 6, 12}, and i == 3.
                we will get num == 3, r == 1.
                Since {6, 12} already had gcd == 6,
                we will -r later.
            */
        }
        dp[i] = (num * (num-1) / 2) - r;  // number of pairs whose gcd is i = C(num, 2) - r
    }

    cout << dp[1] << endl;  // number of pairs whose gcd == 1 -> number of coprime pairs
}