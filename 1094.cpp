#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int x = 0, c = 0;
	cin >> x;
	for(int i = 6; i >= 0; i--) {
		if(x >= pow(2, i)){
			x -= pow(2, i);
			c++;
		}
	}
	cout << c;
	return 0;
}
