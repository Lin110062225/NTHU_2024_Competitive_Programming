#include <bits/stdc++.h>
#define ll long long
using namespace std;

class SegTree {
private:
    struct Node {
        ll val, tag, set_tag;
    };
    vector<int> arr;
    vector<Node> seg;

    ll get_val(int l, int r, int id) {
        if (seg[id].set_tag) return (r-l+1) * (seg[id].set_tag + seg[id].tag);
        return seg[id].val + (r-l+1) * seg[id].tag;
    }

    void pull(int l, int r, int id) {
        int mid = (l+r) / 2;
        seg[id].val = get_val(l, mid, id*2) + get_val(mid + 1, r, id*2 + 1);
    }

    void push(int l, int r, int id) {
        seg[id].val = get_val(l, r, id);
        if (seg[id].set_tag) {
            seg[id*2].set_tag = seg[id*2 + 1].set_tag = seg[id].set_tag;
            seg[id*2].tag = seg[id*2 + 1].tag = 0;
            seg[id].set_tag = 0;
        }
        seg[id*2].tag += seg[id].tag;
        seg[id*2 + 1].tag += seg[id].tag;
        seg[id].tag = 0;
    }

    void build(int l, int r, int id = 1) {
        if (l == r) {
            seg[id].val = arr[l];
            return;
        }
        int mid = (l+r) / 2;
        build(l, mid, 2*id);
        build(mid + 1, r, 2*id + 1);
        pull(l, r, id);
    }

public:
    SegTree(int n, vector<int> &A): seg(4*n), arr(A) {build(0, n-1);}

    void update(int l, int r, int ul, int ur, int v, int id = 1) {
        if (ul > r || ur < l) return;
        if (ul <= l && ur >= r) {
            seg[id].tag += v;
            return;
        }
        int mid = (l+r) / 2;
        push(l, r, id);
        update(l, mid, ul, ur, v, id*2);
        update(mid + 1, r, ul, ur, v, id*2 + 1);
        pull(l, r, id);
    }

    void set_val(int l, int r, int ul, int ur, int v, int id = 1) {
        if (ul > r || ur < l) return;
        if (ul <= l && ur >= r) {
            seg[id].set_tag = v;
            seg[id].tag = 0;
            return;
        }
        int mid = (l+r) / 2;
        push(l, r, id);
        set_val(l, mid, ul, ur, v, id*2);
        set_val(mid + 1, r, ul, ur, v, id*2 + 1);
        pull(l, r, id);
    }

    ll query(int l, int r, int ql, int qr, int id = 1) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && qr >= r) return get_val(l, r, id);
        push(l, r, id);
        int mid = (l+r) / 2;
        return query(l, mid, ql, qr, 2*id) + query(mid + 1, r, ql, qr, 2*id + 1);
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    SegTree st(n, arr);

    while (q--) {
        int op, a, b, x;
        cin >> op >> a >> b;
        if (op == 1) {
            cin >> x;
            st.update(0, n-1, a-1, b-1, x);
        }
        else if (op == 2) {
            cin >> x;
            st.set_val(0, n-1, a-1, b-1, x);
        }
        else {
            cout << st.query(0, n-1, a-1, b-1) << endl;
        }
    }
}