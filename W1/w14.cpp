#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    vector<string> ans;
    do {
        ans.push_back(s);
    }
    while(next_permutation(s.begin(), s.end()));
    cout << ans.size() << endl;
    for (string t: ans) {
        cout << t << endl;
    }
}