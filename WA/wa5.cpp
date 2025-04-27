#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.length(), m = s2.length();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for (int i = 0; i <= n; i++) dp[i][0] = i;  // if length of s2 is 0, we need s1.length() moves
    for (int j = 0; j <= m; j++) dp[0][j] = j;  // same as above

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // if s1[i-1] != s2[j-1], choose the minimum moves before and +1
            dp[i][j] = (s1[i-1] == s2[j-1])? dp[i-1][j-1]: min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
        }
    }
    cout << dp[n][m] << endl;
}