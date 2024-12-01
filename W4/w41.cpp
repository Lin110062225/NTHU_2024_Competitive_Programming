#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i + 1;
    }
    sort(arr.begin(), arr.end());

    for (int i = 1; i < n-1; i++) {
        int target = x - arr[i].first;
        int l = 0, r = n-1;
        while (l != r) {
            int gap = target - arr[l].first - arr[r].first;
            if (l != i && r != i && gap == 0) {
                cout << arr[l].second << ' ' << arr[i].second << ' ' << arr[r].second << endl;
                return 0;
            }
            if (gap > 0) l++;
            else r--;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}