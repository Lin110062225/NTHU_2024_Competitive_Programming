#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool cmp(tuple<ll, int, int, int> &a, tuple<ll, int, int, int> &b) {
    if (get<0>(a) == get<0>(b)) {
        if (get<1>(a) == get<1>(b)) {
            if (get<2>(a) == get<2>(b)) {
                return get<3>(a) < get<3>(b);  // order
            }
            else return get<2>(a) > get<2>(b);  // people
        }
        else return get<1>(a) > get<1>(b);  // max
    }
    else return get<0>(a) > get<0>(b);  // bananas
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> groups_info(n);
        vector<tuple<ll, int, int, int>> groups(n, make_tuple(0, 0, 0, 0));  // (bananas, max, people, order)

        for (int i = 0; i < n; i++) {
            int mx = -1;
            int k;
            cin >> k;
            for (int j = 0; j < k; j++) {
                int banana;
                cin >> banana;
                if (banana > mx) mx = banana;
                groups_info[i].emplace_back(banana);
                get<0>(groups[i]) += banana;
            }
            get<1>(groups[i]) = mx;
            get<2>(groups[i]) = k;
            get<3>(groups[i]) = i;
        }

        sort(groups.begin(), groups.end(), cmp);

        for (auto g: groups) {
            for (int j = 0; j < get<2>(g); j++) {
                cout << groups_info[get<3>(g)][j] << " \n"[j == get<2>(g)-1];
            }
        }
    }
}