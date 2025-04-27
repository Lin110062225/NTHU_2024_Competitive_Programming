#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> arr(n);
    unordered_map<int, pii> mp;

    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            int target = x - arr[i] - arr[j];
            if (mp.count(target) && mp[target].second != i && mp[target].second != j) {
                cout << mp[target].first+1 << ' ' << mp[target].second+1 << ' ' << i+1 << ' ' << j+1 << endl;
                return 0;
            }
        }
        for (int j = i+1; j < n; j++) {
            mp[arr[i] + arr[j]] = {i, j};
        }
    }
    
    cout << "IMPOSSIBLE" << endl;
}