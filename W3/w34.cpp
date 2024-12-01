#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    string s;
    while (getline(cin, s)) {
        // don't use string for answer
        // list is better than vector here
        list<char> ans;
        auto ptr = ans.begin();
        for (auto c: s) {
            if (c == '[') ptr = ans.begin();
            else if (c == ']') ptr = ans.end();
            else ans.emplace(ptr, c);
        }
        for (auto c: ans) cout << c;
        cout << endl;
    }
}