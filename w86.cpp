#include <bits/stdc++.h>
using namespace std;

class DS {
private:
    vector<int> parent, rank;
public:
    DS(int n): parent(n), rank(n) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        if (x == parent[x]) return x;
        parent[x] = find(parent[x]);
        return parent[x];
    }
    void join(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) return;
        if (rank[pa] < rank[pb]) parent[pa] = pb;
        else if (rank[pa] > rank[pb]) parent[pb] = pa;
        else {
            parent[pb] = pa;
            rank[pa]++;
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    DS card(n);
    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        card.join(x-1, y-1);  // z doesn't matter
    }

    vector<int> cnt(n, 0);
    for (int i = 0; i < n; i++) {
        cnt[card.find(i)]++;
    }
    int cost = 0;
    for (int i = 0; i < n; i++) {
        if (cnt[i] > 0) cost++;
    }
    cout << cost << endl;
}