#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll L, R;
int n, k;
vector<ll> arr;

bool greater_than(ll mid) {
    ll sum = 0;
    int sub = 1;  // one array

    for (int i = 0; i < n; i++) {
        if (sum + arr[i] > mid) {
            sub++;
            sum = 0;
        }
        sum += arr[i];
    }
    
    // to get min sum
    // -> frequency of using "R = mid" should more than "L = mid + 1"
    // -> use ">" instead of ">=" here
    return sub > k;  
}

int main() {
    cin >> n >> k;
    L = R = 0;

    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        arr.emplace_back(x);
        L = max(L, x);  // find the largest number
        R += x;
    }
    
    // the maximum sum in the optimal division is >= L and <= R
    while (L < R) {
        ll mid = L + (R-L) / 2;
        if (greater_than(mid)) {
            L = mid + 1;
        }
        else {
            R = mid;
        }
    }

    cout << L << endl;
}