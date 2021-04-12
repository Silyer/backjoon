#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	int n = 0;
	int a[1000001] = {0};
	for(int i = 0; i < s.size(); i++){
		n = s[i] - '0';
		if(n >= 4) {//0 - 012 / 1 - 345 / 2 - 678 / 3 - 9 10 11
			a[i * 3] = 1;
			n -= 4;
		}
		else a[i * 3] = 0;
		if(n >= 2) {
			a[i * 3 + 1] = 1;
			n -= 2;
		}
		else a[i * 3 + 1] = 0;
		if(n >= 1) {
			a[i * 3 + 2] = 1;
			n -= 1;
		}
		else a[i * 3 + 2] = 0;
	}
	if(s == "0") cout << "0";
	else if(a[0] == 0 && a[1] == 0) for(int i = 2; i < s.size() * 3; i++) cout << a[i];
	else if(a[0] == 0) for(int i = 1; i < s.size() * 3; i++) cout << a[i];
	else for(int i = 0; i < s.size() * 3; i++) cout << a[i];

	return 0;
}
