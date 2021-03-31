#include <iostream>
using namespace std;

int main() {
	int n = 0, sum = 0;
	int a[9] = {0};
	cin >> n;
	
	for(int i = 0; i < 9; i++) {
		cin >> a[i];
		sum += a[i];
	}
	cout << n - sum;
	return 0;
}
