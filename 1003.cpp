#include <iostream>
#include <string>
using namespace std;

int main() {
	int t;
	int d[41][2] = {0};
	cin >> t;
	while(t--){
		int n, zeon[2] = {0};
		cin >> n;
		d[0][0] = 1;
		d[0][1] = 0;
		d[1][0] = 0;
		d[1][1] = 1;
		for(int i = 2; i <= n; i++) {
			for(int j = 0; j < 2; j++) {
				d[i][j] = d[i - 1][j] + d[i - 2][j];
			}
			
		}
		cout << d[n][0] << " " << d[n][1] << "\n";
	}
	return 0;
}
