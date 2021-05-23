#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); i++) {
			if(s[i] < 44) s[i] += 20;
	}

	for(int i = 0; i < s.size(); i++) {
		
		s[i] -= 3;
		cout << s[i];
	}
	
	return 0;
}
