#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n, k, y, p, q, m;
    cin >> n >> k >> y >> p >> q >> m;

    vector<ll> arr(n+1), pre(n+1);
    arr[1] = pre[1] = y;
    arr[0] = pre[0] = 0;
    ll ans = y * y;
    
    deque<pair<int, ll>> q_in, q_de;
    if (pre[1] >= 0) q_in.push_back(make_pair(0, pre[0]));
    if (pre[1] <= 0) q_de.push_back(make_pair(0, pre[0]));
    q_in.push_back(make_pair(1, pre[1]));
    q_de.push_back(make_pair(1, pre[1]));
    
    for (int i = 2; i <= n; i++) {
        arr[i] = (arr[i-1] * p + q) % m;
        pre[i] = arr[i] + pre[i-1];

        while (!q_in.empty() && q_in.back().second > pre[i]) {
            q_in.pop_back();
        }
        while (!q_de.empty() && q_de.back().second < pre[i]) {
            q_de.pop_back();
        }
        while (q_in.front().first < i-k) {
            q_in.pop_front();
        }
        while (q_de.front().first < i-k) {
            q_de.pop_front();
        }

        ll mx = max(abs(pre[i] - q_in.front().second), abs(pre[i] - q_de.front().second));
        ans ^= (mx * mx);

        q_in.push_back(make_pair(i, pre[i]));
        q_de.push_back(make_pair(i, pre[i]));
    }
    
    /*
    priority_queue<pair<ll, int>> pq_de;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq_in;
    pq_in.push(make_pair(pre[0], 0));
    pq_de.push(make_pair(pre[0], 0));
    pq_in.push(make_pair(pre[1], 1));
    pq_de.push(make_pair(pre[1], 1));

    for (int i = 2; i <= n; i++) {
        arr[i] = (arr[i-1] * p + q) % m;
        pre[i] = arr[i] + pre[i-1];
        while (pq_in.top().second < i-k) {
            pq_in.pop();
        }
        while (pq_de.top().second < i-k) {
            pq_de.pop();
        }
        ll mx = max(abs(pre[i] - pq_in.top().first), abs(pre[i] - pq_de.top().first));
        ans ^= (mx * mx);
        pq_in.push(make_pair(pre[i], i));
        pq_de.push(make_pair(pre[i], i));
    }
    */
    cout << ans << endl;
}