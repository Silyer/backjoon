#include <iostream>                         //해싱의 
#include <string>
using namespace std;

int main() {
	long long l, h = 0, r = 1;
	cin >> l;
	string s;
	cin >> s;
	for(int i = 0; i < l; i++){
		h = (h + (s[i] - 96) * r) % 1234567891;
		r = (r * 31) % 1234567891;
	} 
	cout << h;
	return 0;
}
