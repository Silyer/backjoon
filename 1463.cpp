#include <iostream>
using namespace std;

int main() {
	int d[1000000] = {0};
	int x = 0;
	cin >> x;
	
	d[1] = 0;
	for(int i = 2; i <= x; i++) {
		d[i] = d[i - 1] + 1;
		if(i % 2 == 0 && d[i] > d[i / 2] + 1) d[i] = d[i / 2] + 1;
		if(i % 3 == 0 && d[i] > d[i / 3] + 1) d[i] = d[i / 3] + 1;
	}
	cout << d[x];
	return 0;
}
