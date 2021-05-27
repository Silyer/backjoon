#include <iostream>
#include <string>
using namespace std;
bool pri(int n) {
	if (n < 2) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int main() {
	while(1) {
		int n, c = 0;
		cin >> n;
		if(n == 0) break;
		for(int i = n + 1; i <= 2 * n; i++) if(pri(i)) c++;
		cout << c << "\n";
	}
	return 0;
}
