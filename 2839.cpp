#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int fi, th;
	fi =  n / 5;
	while(1) {
		if(fi < 0) {
			cout << "-1";
			return 0;
		}
		if((n - fi * 5) % 3 == 0) {
			th = (n - fi * 5) / 3;
			break;
		}
		fi--;
	}
	cout << fi + th;
	return 0;
}
