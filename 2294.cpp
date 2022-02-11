#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int c[101];
	int d[100001];
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 1; i < 100001; i++) d[i] = 100001;
	d[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = c[i]; j <= k; j++) {
			d[j] = min(d[j], d[j - c[i]] + 1);  //
		}
	}
	if (d[k] == 100001) d[k] = -1;
	cout << d[k];
	return 0;
}
