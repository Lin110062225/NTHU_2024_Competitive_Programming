#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, k;
vector<pair<ll, ll>> horses;
vector<ll> opponent;

bool check(int x) {
    vector<ll> tmp(n, 0);
    int win = 0;
    
    for (int i = 0; i < n; i++) {
        // x days
        tmp[i] = horses[i].first + horses[i].second * x;
    }
    sort(tmp.begin(), tmp.end());

    for (int i = k-1, j = n-1; i >= 0; i--, j--) {
        if (opponent[i] < tmp[j]) {
            win++;
        }
    }
    return win == k;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> n >> k;

        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            horses.emplace_back(make_pair(a, b));
        }
        for (int i = 0; i < n; i++) {
            int c;
            cin >> c;
            opponent.emplace_back(c);
        }
        sort(opponent.begin(), opponent.end());
        // for (auto t: horses) cout << t.first << ' ' << t.second << '\n';
        // for (auto t: opponent) cout << t << '\n';

        ll L = 0, R = 1e9, ans = -1;
        while (L < R) {
            ll mid = L + (R-L) / 2;
            if (check(mid)) {
                // too many days
                R = mid;
                ans = mid;
                // cout << "R:" << R << endl;
            }
            else {
                L = mid + 1;
                // cout << "L:" << L << endl;
            }
        }

        cout << ans << endl;

        horses.clear();
        opponent.clear();
    }
}

/*
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

struct Horse {
    ll speed, growth;
    Horse(ll s, ll g) : speed(s), growth(g) {}
    
    ll getSpeed(ll days) const {
        return speed + growth * days;
    }
};

int n, k;
vector<Horse> horses;
vector<ll> opponent;

bool check(ll days) {
    vector<ll> my_speeds;
    for (const auto& horse : horses) {
        my_speeds.push_back(horse.getSpeed(days));
    }
    
    // Sort my horses' speeds in ascending order
    sort(my_speeds.begin(), my_speeds.end());
    
    int wins = 0;
    int my_idx = n - 1;  // Start with my fastest horse
    
    // Match against opponent's horses from fastest to slowest
    for (int opp_idx = n - 1; opp_idx >= 0 && my_idx >= 0; opp_idx--) {
        if (my_speeds[my_idx] > opponent[opp_idx]) {
            wins++;
            my_idx--;
        }
    }
    
    return wins >= k;
}

ll solve() {
    // Binary search for the minimum number of days
    ll left = 0;
    ll right = 2e9;  // Increased upper bound to handle large values
    ll result = -1;
    
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        
        if (check(mid)) {
            result = mid;
            right = mid - 1;  // Try to find a smaller valid answer
        } else {
            left = mid + 1;
        }
    }
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        cin >> n >> k;
        
        horses.clear();
        opponent.clear();
        
        // Read my horses
        for (int i = 0; i < n; i++) {
            ll speed, growth;
            cin >> speed >> growth;
            horses.emplace_back(speed, growth);
        }
        
        // Read opponent's horses
        for (int i = 0; i < n; i++) {
            ll speed;
            cin >> speed;
            opponent.push_back(speed);
        }
        
        // Sort opponent's horses (they will use fastest to slowest)
        sort(opponent.begin(), opponent.end());
        
        cout << solve() << endl;
    }
    
    return 0;
}
*/