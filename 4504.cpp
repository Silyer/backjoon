#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	while(1) {
		int a;
		cin >> a;
		if(a == 0) return 0;
		else {
			if(a % n == 0) cout << a << " is a multiple of " << n << ".\n";
			else cout << a << " is NOT a multiple of " << n << ".\n";
		}
	}
	return 0;
}
