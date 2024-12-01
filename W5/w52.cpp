#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        // deque can be used as stack
        deque<pair<int, int>> dq;  // (height, id)
        ll ans = -1;
        int h;

        for (int i = 0; i < n; i++) {
            cin >> h;
            int cn = i;
            // record and pop
            while (dq.size() && h < dq.back().first) {
                cn = dq.back().second;
                ans = max(ans, 1LL * (i - cn) * dq.back().first);
                dq.pop_back();
            }
            dq.emplace_back(make_pair(h, cn));
        }

        // don't forget the last calculation h = 0
        while (dq.size() && 0 < dq.back().first) {
            ans = max(ans, 1LL * (n - dq.back().second) * dq.back().first);
            dq.pop_back();
        }

        cout << ans << endl;
    }
}