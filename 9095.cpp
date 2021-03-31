#include <iostream>
using namespace std;

int main() {
	 //d[n] = d[n - 1] + d[n - 2] + d[n - 3]
	int t = 0;
	cin >> t;
	while(t--) {
		int n = 0;
		int d[1000] = {0};
		cin >> n;
		
		d[0] = 1; // 공집합
		d[1] = 1; d[2] = 2;
		for(int i = 3; i <= n; i++){
			d[i] = d[i - 1] + d[i - 2] + d[i - 3];
		}
		cout << d[n] << "\n";
	}
	return 0;
}
