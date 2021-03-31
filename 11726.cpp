#include <iostream>
using namespace std;

int main() {
	int d[1000] = {0};
	int n = 0;
	cin >> n;
	
	d[0] = 1;
	d[1] = 1;
	
	for(int i = 2; i <= n; i++) {
		d[i] = d[i - 1] + d[i - 2]; //점화식 
		d[i] %= 10007;
	}

	cout << d[n];
	return 0;
}
