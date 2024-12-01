#include <bits/stdc++.h>
using namespace std;

int n, m;
int p[22];
vector<int> ans;

void f(int i, int j) {
    // i -> which element
    // j -> how many did i get
    if (i == n) {
        if (j == m) {
            for (int k = 0; k < m; k++) {
                cout << ans[k] << " \n"[k == m-1];
            }
        }
        return;
    }
    if (j < m) {
        ans.push_back(p[i]);
        f(i+1, j+1);
        ans.pop_back();
    }
    f(i+1, j);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> p[i];
    f(0, 0);
}