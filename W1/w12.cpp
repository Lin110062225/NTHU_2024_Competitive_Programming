#include <iostream>
using namespace std;

int main() {
  	int n;
  	cin >> n;
  	for (int i = 0; i < (1 << n); i++) {
      int num = i ^ (i >> 1), p = n;
      while (p--) {
        cout << (num & 1);
        num >>= 1;
      }
      cout << endl;
    }
}