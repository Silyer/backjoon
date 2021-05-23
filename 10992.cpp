#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	if(n == 1) cout << "*";
	else{
		for(int i = 0; i < n - 1; i++){
			for(int b = 0; b < n - (i + 1); b++) cout << " ";
			cout << "*";
			if(i > 0) {
				for(int b = 0; b < 2 * i - 1; b++) cout << " ";
				cout << "*";
			}
			cout << "\n";
		}
		for(int i = 0; i < 2 * n - 1; i++) cout << "*";
	}
	return 0;
}
