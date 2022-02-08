#include <iostream>   // 머지 소트를 이용한 풀이
#include <vector>
using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> a(n + 1), b(m + 1);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < m; i++) scanf("%d", &b[i]);
	int ai = 0, bi = 0;
	while (ai < n && bi < m) {
		if (a[ai] < b[bi]) printf("%d ", a[ai++]);
		else printf("%d ", b[bi++]);
	}
	while (ai < n) printf("%d ", a[ai++]);
	while (bi < m) printf("%d ", b[bi++]);
	return 0;
}
