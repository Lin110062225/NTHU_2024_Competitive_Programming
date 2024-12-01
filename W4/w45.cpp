#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, c;
    cin >> n >> c;
    vector<pair<int, int>> points(n);

    double p = 0;
    double cost = 0;

    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
        p += points[i].first;
        cost += pow(c - points[i].second, 2);
    }
    p /= n;

    for (int i = 0; i < n; i++) {
        cost += pow(p - points[i].first, 2);
    }
    printf("%.15f\n", cost);
}