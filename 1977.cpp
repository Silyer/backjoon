#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int m, n, c = 0, sum = 0, min = 10000;
	int a[101];
	cin >> m >> n;
	for(int i = 0; i < 100; i++) {
		a[i] = pow(i + 1, 2);
		if(m <= a[i] && a[i] <= n) {
			sum += a[i];
			if(min > a[i]) min = a[i];
			c++;
		}
	}
	
	if(c == 0) cout << "-1";
	else cout << sum << "\n" << min;
	return 0;
}
