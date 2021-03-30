#include <iostream>
using namespace std;

int main() {
	int n = 0;
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int s = 0; s <= i; s++) cout << "*";
		for(int b = 2 * (n - i - 1); b > 0; b--) cout << " ";
		for(int s = 0; s <= i; s++) cout << "*";
		cout << "\n";
	}
	for(int i = n - 1; i > 0; i--) {
		for(int s = 0; s < i; s++) cout << "*";
		for(int b = 2 * (n - i); b > 0; b--) cout << " ";
		for(int s = 0; s < i; s++) cout << "*";
		cout << "\n";
	}
	return 0;
}
