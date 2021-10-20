#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n + 1, 0), d(n + 1, 0);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	d[1] = a[1];
	d[2] = a[1] + a[2];
	d[3] = max(a[1] + a[3], a[2] + a[3]);
	for(int i = 4; i <= n; i++){
		d[i] = max(d[i - 2] + a[i], d[i - 3] + a[i - 1] + a[i]);
	} 
	cout << d[n];
	return 0;
}

/*
d[n] = 계단 점수 최대값
d[1] = a[1]
d[2] = a[1] + a[2]
d[3] = a[1] + a[3] / a[2] + a[3]
d[4] = d[2] + a[4] / d[1] + a[3] + a[4]
d[5] = d[3] + a[5] / d[2] + a[4] + a[5]
*/
