#include <iostream>
using namespace std;

int main() {
	int n, k, c = 0;
	int a[11] = {0};
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	for(int i = n - 1; i >= 0; i--) {
		while(k >= a[i]) {
			k -= a[i];
			c++;
		}
	}
	cout << c;
	return 0;
}
