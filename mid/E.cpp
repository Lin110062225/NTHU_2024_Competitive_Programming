#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<int> q1;  // top is the largest
    priority_queue<int, vector<int>, greater<int>> q2;  // top is the smallest

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        q2.push(x);
        if (!(i % 4)) {
            q1.push(q2.top());
            q2.pop();
        }
        if (q1.size()) {
            while (q2.top() < q1.top()) {
                int t1 = q1.top();
                int t2 = q2.top();
                q1.pop();
                q1.push(t2);
                q2.pop();
                q2.push(t1);
            }
        }
        cout << q2.top() << endl;
    }
}