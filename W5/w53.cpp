#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    deque<pair<int, int>> dq;  // (value, position)
    dq.emplace_back(make_pair(0, 0));

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        while (dq.back().first >= x) {
            dq.pop_back();
        }
        cout << dq.back().second << " \n"[i == n];
        dq.emplace_back(make_pair(x, i));
    }
}