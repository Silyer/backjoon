#include <iostream>
using namespace std;
int main() {
	int n, k; //nCk = nPk / k!
	cin >> n >> k;
	int d[1001][1001] = {0};
	d[0][0] = 1; //0P0 / 0! = 1
	d[0][1] = 0; //0P1 / 1! = 0/1 = 0
	d[1][0] = d[1][1] = 1;
	
	for(int i = 2; i <= n; i++) {
		for(int j = 0; j <= i; j++) {
			d[i][j] = (d[i - 1][j - 1] + d[i - 1][j]) % 10007;
		}
	}
	cout << d[n][k];
	return 0;
}
