#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int k, n;
		cin >> k;
		cin >> n;
		int r[15][15] = {0};
		for(int i = 1; i <= k; i++) {
			for(int j = 1; j <= n; j++) {
        r[0][i] = i;
				r[i][j] = r[i - 1][j] + r[i][j - 1];
			}
		}
		cout << r[k][n] << "\n";
	}
	return 0;
}
