#include <iostream>
using namespace std;

int main() {
	int n, c = 0, a[5];
	cin >> n;
	for(int i = 0; i < 5; i++) {
		cin >> a[i];
		if(n == a[i]) c++;
	}
	cout << c;
	return 0;
}
