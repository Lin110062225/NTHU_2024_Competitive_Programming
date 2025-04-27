#include <bits/stdc++.h>
using namespace std;

int lowbit(int x) {return -x & x;}

// class SegTree {
// private:
//     vector<int> seg, arr;
//     void pull(int id) {
//         seg[id] = seg[2*id] + seg[2*id + 1];
//     }
// public:
//     SegTree(int n, vector<int> &A): seg(4*n), arr(A) {}
//     void build(int l, int r, int id = 1) {
//         if (l == r) {
//             seg[id] = arr[l];
//             return;
//         }
//         int mid = (l+r) / 2;
//         build(l, mid, 2*id);
//         build(mid + 1, r, 2*id + 1);
//         pull(id);
//     }
//     void update(int l, int r, int p, int id = 1) {
//         if (p < l || p > r) return;
//         if (l == r) {
//             seg[id] ^= 1;
//             return;
//         }
//         int mid = (l+r) / 2;
//         update(l, mid, p, 2*id);
//         update(mid + 1, r, p, 2*id + 1);
//         pull(id);
//     }
//     int query(int l, int r, int ql, int qr, int id = 1) {
//         if (ql > r || qr < l) return 0;
//         if (ql <= l && qr >= r) return seg[id];
//         int mid = (l+r) / 2;
//         return query(l, mid, ql, qr, 2*id) + query(mid + 1, r, ql, qr, 2*id + 1);
//     }
// };

class BIT {
private:
    int n;
    vector<int> bit;
public:
    BIT(int n): n(n), bit(n+1) {}
    int query(int x) {
        int res = 0;
        for (; x; x -= lowbit(x)) res += bit[x];
        return res;
    }
    void update(int x, int val) {
        for(; x <= n; x += lowbit(x)) bit[x] += val;
    }
};

class BIT2D {
private:
    int m;
    vector<BIT> bit;
public:
    BIT2D(int m, int n): m(m), bit(m+1, BIT(n)) {}
    int query(int x, int y) {
        int res = 0;
        for(; x; x -= lowbit(x)) res += bit[x].query(y);
        return res;
    }
    void update(int x, int y, int val) {
        for(; x <= m; x += lowbit(x)) bit[x].update(y, val);
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    vector<vector<bool>> arr(n+1, vector<bool>(n+1));
    // Don't use SegTree, it will get TLE
    BIT2D B(n, n);

    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= n; j++) {
            if (s[j-1] == '*') {
                arr[i][j] = true;
                B.update(i, j, 1);
            }
        }
    }

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y, val;
            cin >> x >> y;
            val = arr[x][y]? -1: 1;
            B.update(x, y, val);
            arr[x][y] = !arr[x][y];
        }
        else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            // inclusion-exclusion principle: rectangles area
            cout << B.query(x2, y2) - B.query(x2, y1-1) - B.query(x1-1, y2) + B.query(x1-1, y1-1) << endl;
        }
    }
}