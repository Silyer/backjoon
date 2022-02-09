#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	int n, k;
	int a[5000001];
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	cout << a[k - 1];
	return 0;
}
