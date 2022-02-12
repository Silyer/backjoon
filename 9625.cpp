#include <iostream>
using namespace std;

int main() {
	int k;
	cin >> k;
	int a[50], b[50];
	a[0] = 0;
	b[0] = 0;
	a[1] = 0;
	b[1] = 1;
	for (int i = 2; i <= 45; i++) {
		a[i] = b[i - 1];
		b[i] = a[i - 1] + b[i - 1];
	}
	cout << a[k] << " " << b[k];
	return 0;
}
/*
d[1] = 0 1 b
d[2] = 1 1 ba
d[3] = 1 2 bab
d[4] = 2 3 babba d[3] + d[2]
d[5] = 3 5 babbabab	d[4]
d[6] = 5 8 babbababbabba
d[7] = 8 13 babbababbabbababbabab
*/
