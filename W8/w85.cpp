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
    int n, q;
    cin >> n >> q;
    DS seq(n+1);
    while (q--) {
        int l, r;
        cin >> l >> r;
        seq.join(l-1, r);  // l-1 is for concatenation
    }
    if (seq.find(0) == seq.find(n)) cout << "Yes\n";
    else cout << "No\n";
}