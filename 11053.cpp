#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, max = 0;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	
	vector<int> d(n);
	for(int i = 0; i < n; i++) {
		d[i] = 1;
		for(int j = 0; j < n; j++) {
			if(a[j] < a[i] && d[i] < d[j] + 1) d[i] = d[j] + 1; 
			if(max < d[i]) max = d[i];
		}
	}
	cout << max;
	return 0;
}
