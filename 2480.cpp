#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int d[3];
	int s[7] = { 0, };
	for (int i = 0; i < 3; i++) {
		cin >> d[i];
		s[d[i]]++;
	}
	sort(d, d + 3);
	for (int i = 1; i <= 6; i++) {
		if (s[i] == 3) {
			cout << 10000 + 1000 * i;
			return 0;
		}
		if (s[i] == 2) {
			cout << 1000 + 100 * i;
			return 0;
		}
	}
	cout << 100 * d[2];
	return 0;
}
