#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    // sort from small to large, ex: 1 2 3 4 5 6
    priority_queue<int> front;  // top is largest, 1 2 3(top)
    priority_queue<int, vector<int>, greater<int>> back;  // top is smallest, 4(top) 5 6

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (front.size() && x > front.top()) back.push(x);
        else front.push(x);

        // make it front.size == back.size or front.size == back.size+1
        if (front.size() > back.size() + 1) {
            back.push(front.top());
            front.pop();
        } else if (back.size() > front.size()) {
            front.push(back.top());
            back.pop();
        }
        cout << front.top() << " \n"[i==n-1];
    }

}