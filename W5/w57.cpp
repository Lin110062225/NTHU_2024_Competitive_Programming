#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, tmp;
    cin >> n >> k;
    vector<int> arr;
    deque<pair<int, int>> dq;

    for (int i = 0; i < n; i++) {
        cin >> tmp;
        arr.emplace_back(tmp);
    }
    
    for (int i = 0; i < n+k-1; i++) {
        if (!dq.empty() && dq.front().second == i-k) {
            dq.pop_front();
        }
        int cur = arr[i%n];
        while (!dq.empty() && dq.back().first < cur) {
            dq.pop_back();
        }
        dq.push_back(make_pair(cur, i%n));
        if (i > k-2) {
            cout << dq.front().first << " \n"[i == n+k-2];
        }
    }
}

// #include <iostream>
// #include <vector>
// #include <deque>
// #include <climits>

// using namespace std;

// int main() {
//     int n, k, tmp;
//     cin >> n >> k;
    
//     vector<int> arr;
//     deque<pair<int, int>> dq;
    
//     // Read initial n elements
//     for (int i = 0; i < n; i++) {
//         cin >> tmp;
//         arr.push_back(tmp);
//     }
    
//     // Process the circular array
//     for (int i = 0; i < n + k - 1; i++) {
//         // Remove elements outside the current window
//         if (!dq.empty() && dq.front().second == i - k) {
//             dq.pop_front();
//         }
        
//         // Get the current element (handling circular nature)
//         int current = arr[i % n];
        
//         // Remove smaller elements from the back of the deque
//         while (!dq.empty() && dq.back().first < current) {
//             dq.pop_back();
//         }
        
//         // Add current element to the deque
//         dq.push_back({current, i});
        
//         // Print the maximum for the current window
//         if (i >= k - 1) {
//             cout << dq.front().first << (i == n + k - 2 ? "\n" : " ");
//         }
//     }
    
//     return 0;
// }