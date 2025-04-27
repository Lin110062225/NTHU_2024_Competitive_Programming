#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pii> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i].first >> s[i].second;
    }
    sort(s.begin(), s.end());
    vector<int> dp;
    for (int i = 0; i < n; i++) {
        // find the largest value in dp less equal than s[i].second
        auto it = lower_bound(dp.begin(), dp.end(), s[i].second, greater<int>());
        // if every value is larger than s[i].second => layer++
        if (it == dp.end()) dp.emplace_back(s[i].second);
        // else update value
        else *it = s[i].second;
    }
    cout << dp.size() << endl;  // number of layers
}