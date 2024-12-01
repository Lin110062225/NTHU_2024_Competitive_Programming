#include <bits/stdc++.h>
using namespace std;

int lowbit(int x) { return x & (-x); }

void move(int i, int rings) {
    if (!rings) return;

    cout << "Move ring " << __lg(i)+1;
    if (rings & i) cout << " out" << endl;
    else cout << " in" << endl;

    rings ^= i;

    int next_bit = lowbit(rings) << 1;
    if ((next_bit & rings)) {
        if (i == next_bit) move(1, rings);
        else move(next_bit, rings);
    }
    else {
        if (i == 1) move(next_bit, rings);
        else move(1, rings);
    }
}

int main() {
    int n;
    cin >> n;
    if (n % 2) move(1, (1<<n)-1);
    else move(2, (1<<n)-1);
}