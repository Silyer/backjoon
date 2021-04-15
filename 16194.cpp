#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, m = 0;
	cin >> n;
	
	int *p = new int[n + 1];
	int *d = new int[n + 1];
	for(int i = 1; i <= n; i++) cin >> p[i];
	for(int i = 1; i <= n; i++) d[i] = 10000000;
	d[0] = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= i; j++) d[i] = min(d[i], d[i - j] + p[j]);
	}
	cout << d[n];
	// d[n] = min(d[n- i] + p[i]), 초기값을 제한보다 넘게
	// 1 <= i <= n
	return 0;
}
