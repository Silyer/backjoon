#include <iostream>
using namespace std;

int main() {
	int n = 0, x = 0;
	cin >> n;
	if(n == 1) cout << "1";
	else {
		for(int i = 0; i <= 1000000; i++) {
			if(n > 0) {
				if(i == 0) n--;
				else n -= 6 * i;
			}
			else {
				x = i;
				break;
			}
		}	
		cout << x;
	}
		
	//1 = 1 / 2~7 = 2 / 8~19 = 3 / 20~37 = 4 / 38~61 = 5
	//  1        6          12       18           24

	return 0;
}
