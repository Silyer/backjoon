#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> d(n + 1, 0);                  //점화식 : 홀수 = 0, d[2] = 3, d[4] = 11, d[6] = 41..
	d[0] = 1;                                 //d[i] = 3 * d[i - 2] + 2 * d[i - 4] + 2 * d[i - 6] + ...
	for(int i = 2; i <= n; i += 2) {
		for(int j = 2; j <= i; j += 2) {
			if(j == 2) d[i] += 3 * d[i - j];
			else d[i] += 2 * d[i - j];
		}
	}
	cout << d[n];
	return 0;
}
