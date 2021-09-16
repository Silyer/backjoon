#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//d[n] = min(d[n - i^2]) + 1	(1 <= i <= 루트n)
int main() { 
	int n;
	cin >> n;
	vector<int> d(n + 1);
	for(int i = 1; i <= n; i++) {
		d[i] = i;
		for(int j = 1; j * j <= i; j++) {
			d[i] = min(d[i], d[i - j * j] + 1);
		}
	}
	cout << d[n];
}
