#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> tasks(n);  // (duration, deadline)
    for (int i = 0; i < n; i++) {
        cin >> tasks[i].first >> tasks[i].second;
    }
    sort(tasks.begin(), tasks.end());
    ll finish = 0;
    ll reward = 0;
    for (int i = 0; i < n; i++) {
        finish += tasks[i].first;
        reward += (tasks[i].second - finish);
    }
    cout << reward;
}