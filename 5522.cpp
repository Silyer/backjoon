#include <iostream>
using namespace std;

int main() {
	int a[5], c = 0;
	for(int i = 0; i < 5; i++) {
		cin >> a[i];
		c += a[i];
	}
	cout << c;
}
