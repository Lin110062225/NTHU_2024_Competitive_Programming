#include <bits/stdc++.h>
#define ll long long
using namespace std;

class SegTree {
private:
    struct Node {
        ll val, tag;
    };
    vector<Node> seg;
    vector<int> arr;

    ll get_val(int l, int r, int id) {
        return (r - l + 1) * seg[id].tag + seg[id].val;
    }

    void pull(int l, int r, int id) {
        int mid = (l + r) / 2;
        seg[id].val += get_val(l, mid, 2*id) + get_val(mid + 1, r, 2*id + 1);
    }

    void push(int l, int r, int id) {
        seg[id].val = get_val(l, r, id);
        seg[2*id].tag += seg[id].tag;
        seg[2*id + 1].tag += seg[id].tag;
        seg[id].tag = 0;
    }

public:
    SegTree(int n, vector<int> &A): seg(4*n), arr(A) {}

    void build(int l, int r, int id = 1) {
        if (l == r) {
            seg[id].val = arr[l];
            seg[id].tag = 0;
            return;
        }
        int mid = (l + r) / 2;
        build(l, mid, 2*id);
        build(mid + 1, r, 2*id + 1);
        pull(l, r, id);
    }

    void update(int ul, int ur, int l, int r, int val, int id = 1) {
        if (ul > r || ur < l) return;
        if (ul <= l && ur >= r) {
            seg[id].tag += val;
            return;
        }
        push(l, r, id);  // remember
        int mid = (l + r) / 2;
        update(ul, ur, l, mid, val, 2*id);
        update(ul, ur, mid + 1, r, val, 2*id + 1);
        pull(l, r, id);  // remember
    }

    ll query(int p, int l, int r, int id = 1) {
        if (p < l || p > r) return -1;
        if (l == r) return get_val(l, r, id);
        push(l, r, id);
        int mid = (l + r) / 2;
        return max(query(p, l, mid, 2*id), query(p, mid + 1, r, 2*id + 1));
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
        int type;
        cin >> type;
        if (type == 1) {
            int a, b, u;
            cin >> a >> b >> u;
            st.update(a-1, b-1, 0, n-1, u);
        }
        else {
            int k;
            cin >> k;
            cout << st.query(k-1, 0, n-1) << endl;
        }
    }
}