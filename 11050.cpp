#include <iostream>
using namespace std;

int main() {
	int n, k, kp = 1, npk = 1;
	cin >> n >> k;
	for(int i = k; i > 0; i--) kp *= i;
	for(int i = n; i > n - k; i--) npk *= i;
	cout << npk / kp;
	return 0;
}
