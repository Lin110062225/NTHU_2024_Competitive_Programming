#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> children(n);
    vector<int> parent_cnt(n, 0), ans;

    while (m--) {
        int c1, c2;
        cin >> c1 >> c2;
        children[c1-1].emplace_back(c2-1);
        parent_cnt[c2-1]++;
    }

    // push back the node who has no parent
    for (int i = 0; i < n; i++) {
        if (parent_cnt[i] == 0) {
            ans.emplace_back(i);
        }
    }

    // push back the node who has 1 parent, then 2, 3, 4, ...
    for (int i = 0; i < ans.size(); i++) {
        for (auto t: children[ans[i]]) {
            if (parent_cnt[t] == 1) {
                ans.emplace_back(t);
            }
            parent_cnt[t]--;
        }
    }

    if (ans.size() != n) cout << "IMPOSSIBLE" << endl;
    else {
        for (int i = 0; i < n; i++) {
            cout << ans[i] + 1 << " \n"[i == n-1];
        }
    }
}