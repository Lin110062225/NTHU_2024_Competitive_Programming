#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> students(n);

    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        students[i].first = a + b + c;
        students[i].second = i;
    }

    nth_element(students.begin(), students.begin() + k - 1, students.end(), greater<pair<int, int>>());

    vector<bool> ans(n, false);
    int mn = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (i < k) {
            mn = min(mn, students[i].first);
            ans[students[i].second] = true;
        }
        else {
            if (students[i].first + 300 >= mn) {
                ans[students[i].second] = true;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (ans[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
} 