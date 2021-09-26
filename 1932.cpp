#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, m = 0;
	cin >> n;
	vector<vector<int>> a(n + 2, vector<int> (n + 2, 0)), d(n + 2, vector<int> (n + 2, 0));
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= i; j++) cin >> a[i][j];
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= i; j++)	d[i][j] = max(d[i - 1][j], d[i - 1][j - 1]) + a[i][j];
	}
	for(int i = 1; i <= n; i++) if(m < d[n][i]) m = d[n][i];
	cout << m;
	return 0;
}
