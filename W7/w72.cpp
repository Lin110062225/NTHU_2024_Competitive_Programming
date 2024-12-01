#include <bits/stdc++.h>
#define ll long long
using namespace std;

int x[200001], arr[1000001];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        arr[x[i]]++;
    }

    int ans = 1;
    for (int i = 2; i < 1000001; i++) {  // check each factor from small to big
        int total = 0;
        for (int j = i; j < 1000001; j += i) {
            total += arr[j];
        }
        if (total > 1) ans = i;  // if more than one number have factor i
    }

    cout << ans << endl;
}