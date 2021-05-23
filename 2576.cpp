#include <iostream>
using namespace std;

int main() {
	int n, sum = 0, min = 100;
	for(int i = 0; i < 7; i++) {
		cin >> n;
		if(n % 2 != 0) {
			sum += n;
			if(n < min) min = n;
		}
	}
	if(sum > 0) cout << sum << "\n" << min;
	else cout << "-1";
	return 0;
}
