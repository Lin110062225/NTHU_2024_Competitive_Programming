#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<bool> visited(n+1, false);
        deque<pair<char, int>> dq;

        while (q--) {
            char op;
            int num;
            cin >> op >> num;
            dq.push_back(make_pair(op, num));
        }

        deque<int> a, b;  // ans = a + non_visited + b;

        while (!dq.empty()) {
            char op = dq.back().first;
            int num = dq.back().second;
            dq.pop_back();

            if (visited[num]) continue;

            if (op == 'H') a.push_back(num);
            else b.push_front(num);

            visited[num] = true;
        }

        // where to cout << endl
        int cnt = 0;
        // output
        for (int i = 0; i < a.size(); i++) {
            cout << a[i];
            if (++cnt == n) cout << endl;
            else cout << ' ';
        }
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                cout << i;
                if (++cnt == n) cout << endl;
                else cout << ' ';
            }
        }
        for (int i = 0; i < b.size(); i++) {
            cout << b[i];
            if (++cnt == n) cout << endl;
            else cout << ' ';
        }
    }
}