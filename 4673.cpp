#include <iostream>
using namespace std;
int d(int n) {
	int sum = n;
	while(n > 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}
int main() {
	int n[10001] = {0}, s;
	for(int i = 1; i < 10001; i++) {
		s = d(i);
		if(s < 10001)
			n[s] = 1;
	}
	for(int i = 1; i < 10001; i++) {
		if(n[i] != 1) cout << i << "\n";
	}
	
	
	return 0;
}
