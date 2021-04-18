#include <iostream>
#include <string>
using namespace std;

int main() {
	while(1) {
		string s;
		int c = 0;
		getline(cin, s);
		if(s[0] == '#') return 0;
		for(int i = 0; i < s.size(); i++) {
			if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') c++;
		}
		cout << c << "\n";
	}
	
	return 0;
}
