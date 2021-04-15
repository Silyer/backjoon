#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int a, b, k, re;
		unsigned long long int p = 1, kp = 1;
		cin >> a >> b;
		if(a > b - a) k = b - a;
		else k = a;
		for(int i = 1; i <= k; i++) {
			int j = b - i + 1;
			kp *= i;
			p *= j;
		}
		cout << p / kp << "\n";
		
	}
	return 0;
}
