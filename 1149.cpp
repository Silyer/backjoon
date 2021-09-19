#include <iostream>							//그냥 dp로 풀었으면 될 것을..
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(3, 0);
	vector<vector<int>> d(n + 1, vector<int>(3, 0));
	for(int i = 1; i <= n; i++) {
		cin >> a[0] >> a[1] >> a[2];
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + a[0];
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + a[1];
		d[i][2] = min(d[i - 1][0], d[i - 1][1]) + a[2];
	}
	sort(d[n].begin(),  d[n].end());
	cout << d[n][0];
	return 0;
}
