#include <iostream>
using namespace std;

int main() {
	int re = 0, max = 0;
	int d[4] = {0}, a[4] = {0};
	for(int i = 0; i < 4; i++) cin >> d[i] >> a[i];
	for(int i = 0; i < 3; i++) {
		re += a[i];
		if(max < re) max = re;
		re -= d[i + 1];
	}
	cout << max;
	return 0;
}
