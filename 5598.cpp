#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;

	for(int i = 0; i < s.size(); i++) {
		if(s[i] <= 'C') s[i] += 26;
		s[i] -= 3;
		cout << s[i];
	}
	
	return 0;
}
