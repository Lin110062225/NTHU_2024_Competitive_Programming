#include <bits/stdc++.h>
using namespace std;

int n;
long long sum = 0;
long long mn = LLONG_MAX;
vector<int> apples;

void dfs(int i, long long part) {
    if (i == n) {
        mn = min(mn, abs(sum-part-part));
        return;
    }
    dfs(i+1, part+apples[i]);
    dfs(i+1, part);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        apples.push_back(a);
        sum += a;
    }
    dfs(0, 0);
    cout << mn << endl;
}