#include <bits/stdc++.h>
using namespace std;

class SegTree {
private:
    vector<int> seg, arr;
    
    void pull(int id) {
        seg[id] = min(seg[id*2], seg[id*2 + 1]);
    }

public:
    SegTree(int n, vector<int> &A): seg(4*n), arr(A) {}

    void build(int l, int r, int id = 1) {
        if (l == r) {
            seg[id] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(l, mid, id * 2);
        build(mid + 1, r, id*2 + 1);
        pull(id);
    }

    void update(int p, int val, int l, int r, int id = 1) {
        if (p < l || p > r) return;
        if (l == r) {
            seg[id] = val;
            return;
        }
        int mid = (l + r) / 2;
        update(p, val, l, mid, 2*id);
        update(p, val, mid + 1, r, 2*id + 1);
        pull(id);
    }

    int query(int ql, int qr, int l, int r, int id = 1) {
        if (ql > r || qr < l) return INT_MAX;
        if (ql <= l && qr >= r) return seg[id];
        int mid = (l + r) / 2;
        return min(query(ql, qr, l, mid, id*2), query(ql, qr, mid + 1, r, id*2 + 1));
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    SegTree st(n, arr);
    st.build(0, n-1);

    while (q--) {
        int type, a, b;
        cin >> type >> a >> b;
        if (type == 1) st.update(a-1, b, 0, n-1);
        else cout << st.query(a-1, b-1, 0, n-1) << endl;
    }
}