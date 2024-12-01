#include <bits/stdc++.h>
using namespace std;

int t, n;
vector<int> nums;
vector<int> ans;
set<vector<int>> check;

void dfs(int i, int sum) {
    if (sum == t) {
        // check is important
        if (check.find(ans) != check.end()) return;
        for (int j = 0; j < ans.size(); j++) {
            cout << ans[j] << "+\n"[j == ans.size()-1];
        }
        check.insert(ans);
    }
    if (sum > t || i == n) return;
    ans.push_back(nums[i]);
    dfs(i + 1, sum + nums[i]);
    ans.pop_back();
    dfs(i + 1, sum);
}

int main() {
    while(1) {
        cin >> t >> n;
        if (!n) break;
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            nums.push_back(tmp);
        }
        cout << "Sums of " << t << ":\n";
        dfs(0, 0);
        if (check.empty()) cout << "NONE" << endl;
        nums.clear();
        ans.clear();
        check.clear();
    }
}

// claude version 
// --------------

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <set>
// #include <sstream>

// using namespace std;

// int t, n;
// vector<int> nums;
// vector<int> current;
// set<vector<int>> unique_sums;

// void findSums(int index, int sum) {
//     if (sum == t) {
//         vector<int> sorted_current = current;
//         sort(sorted_current.rbegin(), sorted_current.rend());
//         unique_sums.insert(sorted_current);
//         return;
//     }
//     if (index == n || sum > t) {
//         return;
//     }
    
//     // Include current number
//     current.push_back(nums[index]);
//     findSums(index + 1, sum + nums[index]);
//     current.pop_back();
    
//     // Skip current number
//     findSums(index + 1, sum);
// }

// string vectorToString(const vector<int>& v) {
//     ostringstream oss;
//     for (size_t i = 0; i < v.size(); ++i) {
//         if (i > 0) oss << "+";
//         oss << v[i];
//     }
//     return oss.str();
// }

// int main() {
//     while (true) {
//         cin >> t >> n;
//         if (n == 0) break;
        
//         nums.clear();
//         nums.resize(n);
//         for (int i = 0; i < n; i++) {
//             cin >> nums[i];
//         }
        
//         unique_sums.clear();
//         findSums(0, 0);
        
//         cout << "Sums of " << t << ":\n";
//         if (unique_sums.empty()) {
//             cout << "NONE\n";
//         } else {
//             vector<string> output;
//             for (const auto& sum : unique_sums) {
//                 output.push_back(vectorToString(sum));
//             }
//             sort(output.rbegin(), output.rend());
//             for (const auto& s : output) {
//                 cout << s << "\n";
//             }
//         }
//     }
//     return 0;
// }