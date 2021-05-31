#include <iostream>
using namespace std;

int main() {
	int n, x = 0;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int sum = i, t = i;
		while(t) {
			sum += t % 10;
			t /= 10;
		}
		if(sum == n){
			cout << i;
			x++;
			break;
		}
	}
	if(x == 0) cout << 0;
	return 0;
}
