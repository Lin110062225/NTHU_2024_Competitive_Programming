#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> position = {
    {"elder", 0},
    {"nursy", 1},
    {"kit", 2},
    {"warrior", 3},
    {"appentice", 4},
    {"medicent", 5},
    {"deputy", 6},
    {"leader", 7}
};

bool cmp(tuple<int, int, string> &a, tuple<int, int, string> &b) {
    if (get<0>(a) == get<0>(b)) {  // same pos
        if (get<1>(a) == get<1>(b)) {  // same age
            return get<2>(a) < get<2>(b);
        }
        if (get<0>(a) == 4) {  // appentice case
            return get<1>(a) < get<1>(b);
        }
        return get<1>(a) > get<1>(b);  // other pos case
    }
    return get<0>(a) < get<0>(b);
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<tuple<int, int, string>> cats(n);

        for (int i = 0; i < n; i++) {
            cin >> get<2>(cats[i]);
            string pos;
            cin >> pos;
            get<0>(cats[i]) = position[pos];
            cin >> get<1>(cats[i]);
        }

        sort(cats.begin(), cats.end(), cmp);

        int mn = min(m, n);
        for (int i = 0; i < mn; i++) {
            cout << get<2>(cats[i]) << endl;
        }
    }
}