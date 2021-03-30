#include <iostream>
using namespace std;

int main() {
	int n = 0;
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int b = n - i - 1; b > 0; b--) cout << " ";
		for(int j = 0; j <= i; j++) {
			cout << "* ";
		}
		cout << "\n";
	}
	return 0;
}
