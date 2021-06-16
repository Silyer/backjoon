#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int>> l(n, vector<int>(2, 0));
	for(int i = 0; i < n; i++) cin >> l[i][0] >> l[i][1];
	sort(l.begin(), l.end());
	for(int i = 0; i < n; i++) cout << l[i][0] << " " << l[i][1] << "\n";
	return 0;
}
