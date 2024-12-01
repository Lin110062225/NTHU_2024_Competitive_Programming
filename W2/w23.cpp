#include <bits/stdc++.h>
// #include <chrono>
using namespace std;

bool dfs(vector<int> &sticks, vector<bool> &visited, int &len, int sides, int start, int cur_len) {
    if (sides == 3) {
        return true;
    }
    for (int i = start; i < sticks.size(); i++) {
        if (visited[i]) continue;
        if (cur_len + sticks[i] > len) continue;

        visited[i] = true;
        if (cur_len + sticks[i] == len) {
            if (dfs(sticks, visited, len, sides+1, 0, 0)) {
                return true;
            }
        }
        else {
            if (dfs(sticks, visited, len, sides, i+1, cur_len + sticks[i])) {
                return true;
            }
        }
        visited[i] = false;

        if (i < sticks.size()-1 && sticks[i] == sticks[i+1]) i++;
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    while(n--) {
        int m;
        cin >> m;

        int sum = 0;
        vector<int> sticks(m);

        for (int i = 0; i < m; i++) {
            cin >> sticks[i];
            sum += sticks[i];
        }

        // auto start = chrono::high_resolution_clock::now();

        if (sum % 4) {
            cout << "no" << endl;
            continue;
        }

        sort(sticks.rbegin(), sticks.rend());
        int len = sum / 4;

        if (sticks[0] > len) {
            cout << "no" << endl;
            continue;
        }

        vector<bool> visited(m, false);
        
        if (dfs(sticks, visited, len, 0, 0, 0)) {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }
        // auto stop = chrono::high_resolution_clock::now();
        // auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    }
}

// claude version
// --------------

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// bool canFormSquare(vector<int>& sticks, vector<bool>& used, int sideLength, int sides, int start, int currentLength) {
//     if (sides == 0) {
//         return true;
//     }
    
//     for (int i = start; i < sticks.size(); i++) {
//         if (used[i]) continue;
        
//         if (currentLength + sticks[i] > sideLength) continue;
        
//         used[i] = true;
        
//         if (currentLength + sticks[i] == sideLength) {
//             if (canFormSquare(sticks, used, sideLength, sides - 1, 0, 0)) {
//                 return true;
//             }
//         } else {
//             if (canFormSquare(sticks, used, sideLength, sides, i + 1, currentLength + sticks[i])) {
//                 return true;
//             }
//         }
        
//         used[i] = false;
        
//         // Skip identical sticks to avoid duplicate work
//         while (i + 1 < sticks.size() && sticks[i] == sticks[i + 1]) {
//             i++;
//         }
//     }
    
//     return false;
// }

// int main() {
//     int n;
//     cin >> n;
    
//     while (n--) {
//         int m;
//         cin >> m;
        
//         vector<int> sticks(m);
//         int sum = 0;
        
//         for (int i = 0; i < m; i++) {
//             cin >> sticks[i];
//             sum += sticks[i];
//         }
        
//         if (sum % 4 != 0) {
//             cout << "no" << endl;
//             continue;
//         }
        
//         int sideLength = sum / 4;
        
//         sort(sticks.rbegin(), sticks.rend());
        
//         if (sticks[0] > sideLength) {
//             cout << "no" << endl;
//             continue;
//         }
        
//         vector<bool> used(m, false);
        
//         if (canFormSquare(sticks, used, sideLength, 4, 0, 0)) {
//             cout << "yes" << endl;
//         } else {
//             cout << "no" << endl;
//         }
//     }
    
//     return 0;
// }