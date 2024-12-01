#include <bits/stdc++.h>
using namespace std;

void hanoi(int k, int A, int B, int C) {
    if (k == 1) {
        cout << A << ' ' << C << endl;
    }
    else {
        hanoi(k-1, A, C, B);
        hanoi(1, A, B, C);
        hanoi(k-1, B, A, C);
    }
}

int main() {
    int k;
    cin >> k;
    cout << pow(2, k) - 1 << endl;
    hanoi(k, 1, 2, 3);
}