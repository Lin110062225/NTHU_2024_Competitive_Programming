#include<bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2, ans;
    cin >> s1 >> s2;

    int n = s1.length(), m = s2.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    // We will get dp[n][m], which means the length of LCS of s1(length = n) and s2(length = m).
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = (s1[i-1] == s2[j-1])? dp[i-1][j-1] + 1: max(dp[i-1][j], dp[i][j-1]);
        }
    }
    // Trace back to find the LCS
    for (int i = n, j = m; i > 0 && j > 0; ) {
        if (dp[i][j] == dp[i-1][j]) i--;
        else if (dp[i][j] == dp[i][j-1]) j--;
        else {
            ans += s1[i-1];
            i--, j--;
        }
    }
    // reverse the string we got
    cout << string(ans.rbegin(), ans.rend()) << endl;
}