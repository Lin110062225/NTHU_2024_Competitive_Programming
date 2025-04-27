#include <bits/stdc++.h>
#define ll long long
using namespace std;

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
        int ra = find(a), rb = find(b);
        if (ra == rb) return;
        if (rank[ra] > rank[rb]) parent[rb] = ra;
        else if (rank[ra] < rank[rb]) parent[ra] = rb;
        else {
            parent[rb] = ra;
            rank[ra]++;
        }
    }
};

int n, k, l;

int main() {
    cin >> n >> k >> l;
    US road(n), railway(n);

    for (int i = 0; i < k; i++) {
        int p1, p2;
        cin >> p1 >> p2;
        road.join(p1-1, p2-1);
    }
    for (int i = 0; i < l; i++) {
        int p1, p2;
        cin >> p1 >> p2;
        railway.join(p1-1, p2-1);
    }
    
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n; i++) {
        mp[make_pair(road.find(i), railway.find(i))]++;
    }
    for (int i = 0; i < n; i++) {
        cout << mp[make_pair(road.find(i), railway.find(i))] << " \n"[i == n-1];
    }
}