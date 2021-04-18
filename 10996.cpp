#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;//1 - 0 / 2 3 - 1 / 4 5 - 2 / 6 7 - 3
	for(int i = 1; i <= n; i++) {
		for(int s = 0; s < ((n / 2) + (n % 2)); s++) cout << "* ";
		if(n > 1) {
			cout << "\n";
			for(int s = 0; s < n / 2; s++) cout << " *"; //1 - 0 / 2 3 - 1 / 4 5 - 2 / 6 7 - 3
			cout << "\n";
		}
	}
	return 0;
}
