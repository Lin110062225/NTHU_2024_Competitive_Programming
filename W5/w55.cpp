#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;

    int st = 0;  // num of "ST"
    int len = str.size();
    int s = (str[0] == 'S');  // num of 'S'
    char last = str[0];  // last char

    for (int i = 1; i < len; i++) {
        if (str[i] == 'S') {
            if (last == 'S') s++;
            else {
                s = 1;
                last = 'S';
            }
        }
        else {
            if (last == 'S') {
                st++;
                s--;
                if (!s) last = 'T';
            }
        }
    }

    cout << len - st*2 << endl;
}