#include <iostream>
#include <queue>
using namespace std;

int main() {
	int t;
	long long d[110] = { 0 };
	cin >> t;
	d[0] = 0;
	d[1] = 1;
	d[2] = 1;	
	d[3] = 1;
	d[4] = 2;
	d[5] = 2;
	for (int i = 6; i <= 100; i++) {
		d[i] = d[i - 5] + d[i - 1];
	}
	while (t--) {
		int n;
		cin >> n;
		cout << d[n] << '\n';
	}
	return 0;
}
/*
d[4] = d[1] + d[3]
d[6] = d[1] + d[5]
d[7] = d[2] + d[6]
d[8] = d[3] + d[7]
d[9] = d[4] + d[8]
d[10] = d[5] + d[9]

*/
