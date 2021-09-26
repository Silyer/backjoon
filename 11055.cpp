#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m = 0;
	cin >> n;
	vector<int> a(n + 1, 0);
	for(int i = 0; i < n; i++) cin >> a[i];
	vector<int> d(n + 1, 0);
	for(int i = 0; i < n; i++) {
		d[i] = a[i];
		for(int j = 0; j < n; j++) {
			if(a[j] < a[i] && d[i] < d[j] + a[i]) d[i] = d[j] + a[i];
			if(m < d[i]) m = d[i];
		}
	}
	cout << m;
	return 0;
}
