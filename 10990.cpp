#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	if (n == 1) {
		cout << "*";
		return 0;
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int b = 0; b < n - i - 1; b++) cout << " ";
			cout << "*";
			if (i > 0) {
				for (int b = 0; b < 2 * i - 1; b++) cout << " ";
				cout << "*";
			}
			cout << '\n';
		}
	}
	return 0;
}
