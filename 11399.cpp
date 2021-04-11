#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, min = 0;
	cin >> n;
	int a[1001] = {0};
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	sort(a, a + n);
	for(int i = 0; i < n; i++) min += a[i] * (n - i);
	cout << min;
	return 0;
}
