#include <iostream>
#include <string>
using namespace std;

int main() {
	int c = 0;
	string a[8];
	for(int i = 0; i < 8; i++) {
		cin >> a[i];
		for(int j = 0; j < 8; j++) {
			if(i % 2 == 0 && j % 2 == 0 && a[i][j] == 'F') c++;
			else if(i % 2 != 0 && j % 2 != 0 && a[i][j] == 'F') c++;
		}
	}
	cout << c;
	return 0;
}
