#include <bits/stdc++.h>
using namespace std;

class SegTree {
private:
    vector<int> seg, arr;

    void pull(int id) {
        seg[id] = max(seg[2*id], seg[2*id + 1]);
    }

public:
    SegTree(int n, vector<int> &A): seg(4*n), arr(A) {}

    void build(int l, int r, int id = 1) {
        if (l == r) {
            seg[id] = arr[l];
            return;
        }
        int mid = (l+r) / 2;
        build(l, mid, 2*id);
        build(mid + 1, r, 2*id + 1);
        pull(id);
    }

    void update(int l, int r, int v, int p, int id = 1) {
        if (p < l || p > r) return;
        if (l == r) {
            seg[id] -= v;
            return;
        }
        int mid = (l+r) / 2;
        update(l, mid, v, p, 2*id);
        update(mid+1, r, v, p, 2*id + 1);
        pull(id);
    }

    bool check(int v) {
        return v <= seg[1];
    }

    int search(int l, int r, int v, int id = 1) {
        if (l == r) return l;
        int mid = (l+r) / 2;
        if (seg[2*id] >= v) return search(l, mid, v, 2*id);
        else return search(mid + 1, r, v, 2*id + 1);
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> hotel(n);
    for (int i = 0; i < n; i++) {
        cin >> hotel[i];
    }
    
    SegTree st(n, hotel);
    st.build(0, n-1);

    for (int i = 0; i < m; i++) {
        int val, pos;
        cin >> val;
        if (st.check(val)) {
            pos = st.search(0, n-1, val) ;
            st.update(0, n-1, val, pos);
            cout << pos+1;
        }
        else cout << 0;
        cout << " \n"[i == m-1];
    }
}