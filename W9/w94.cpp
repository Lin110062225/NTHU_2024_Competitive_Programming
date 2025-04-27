#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;

// Kruskal's algorithm

class US {
private:
    vector<int> parent, rank;
public:
    US(int n): parent(n), rank(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (x == parent[x]) return x;
        parent[x] = find(parent[x]);
        return parent[x];
    }
    void join(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) return;
        if (rank[pa] > rank[pb]) parent[pb] = pa;
        else if (rank[pb] > rank[pa]) parent[pa] = pb;
        else {
            parent[pb] = pa;
            rank[pa]++;
        }
    }
};

bool cmp(pair<pii, int> &a, pair<pii, int> &b) {
    return a.second < b.second;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<pii, int>> roads;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        roads.emplace_back(make_pair(make_pair(a-1, b-1), c));
    }
    sort(roads.begin(), roads.end(), cmp);

    ll ans = 0;
    US mst(n);
    for (auto t: roads) {
        if (mst.find(t.first.first) == mst.find(t.first.second)) continue;
        mst.join(t.first.first, t.first.second);
        ans += t.second;
    }

    int root = mst.find(0);
    for (int i = 1; i < n; i++) {
        if (mst.find(i) != root) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    cout << ans << endl;
}