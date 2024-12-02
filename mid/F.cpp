#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int n;
int len, num;
unsigned long long visited;

bool dfs(int cur, int cum, int cnt, vector<int> &sticks) {
    if (cum == len) {
        if (cnt+1 == num) return true;
        else return dfs(0, 0, cnt+1, sticks);
    }

    for (int i = cur; i < n; i++) {
        int new_cum = cum + sticks[i];
        ull shift = 1ull << i;

        if (visited & shift || new_cum > len || (i && sticks[i] == sticks[i-1] && !(visited & (shift >> 1)))) {
            continue;
        }
        visited ^= shift;
        if (dfs(i+1, new_cum, cnt, sticks)) {
            return true;
        }
        visited ^= shift;
        if (cum == 0 || new_cum == len) {
            return false;
        }
    }

    return false;
}

int main() {
    while (cin >> n) {
        if (n == 0) break;
        vector<int> sticks(n);
        // vector<bool> v(n);

        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> sticks[i];
            sum += sticks[i];
        }
        sort(sticks.begin(), sticks.end(), greater<int>());

        bool done = false;
        for (int i = sticks[0]; i <= sum/2; i++) {
            if (sum % i) continue;
            len = i;
            num = sum / i;
            visited = 0;

            if (dfs(0, 0, 0, sticks)) {
                cout << len << endl;
                done = true;
                break;
            }
        }
        if (!done) cout << sum << endl;
    }
}