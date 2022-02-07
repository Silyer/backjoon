#include <iostream>   // 이분 탐색을 통한 풀이
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> m;
	vector<int> b(m);
	for (int i = 0; i < m; i++) cin >> b[i];
	
	sort(a.begin(), a.end());
	int re[500001] = { 0, };
	for (int i = 0; i < m; i++) {
		int l = 0, r = n - 1;
		bool ok = false;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (a[mid] == b[i]) {
				re[i] = 1;
				break;
			}
			if (a[mid] > b[i]) r = mid - 1;
			else l = mid + 1;
		}
	}
	for (int i = 0; i < m; i++) cout << re[i] << ' ';
	return 0;
}
