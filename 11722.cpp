#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m = 0;
	cin >> n;
	vector<int> a(n + 1, 0), d(n + 1, 0);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) {
		d[i] = 1;
		for(int j = 0; j < n; j++) {
			if(a[j] > a[i] && d[i] < d[j] + 1) d[i] = d[j] + 1;
			if(m < d[i]) m = d[i];
		}
	}
	cout << m;
	return 0;
}
