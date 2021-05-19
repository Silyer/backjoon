#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	int *p = new int[n + 1];
	int *d = new int[n + 1];
	for(int i = 1; i <= n; i++) cin >> p[i];
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= i; j++) {
			d[i] = max(d[i], d[i - j] + p[j]);
		}
	}
	cout << d[n];
	// d[n] = max(d[n- i] + p[i])
	// 1 <= i <= n
	return 0;
}
