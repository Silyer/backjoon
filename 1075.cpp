#include <iostream>
using namespace std;

int main() {
	int n, f;
	cin >> n;
	cin >> f;
	n -= n % 100;
	for(int i = 0; i < 100; i++) {
		if((n + i) % f == 0){
			printf("%.2d", i);
			break;
		} 
	}
	return 0;
}
