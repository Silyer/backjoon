#include <iostream>
#include <string>
using namespace std;

int main() {
	while(1) {
		string s;
		int c = 0;
		cin >> s;
		if(s[0] != '0') {
			for(int i = 0; i < s.size(); i++) {
				if(s[i] != s[s.size() - 1 - i]) c++;
			}
			if (c == 0) cout << "yes\n";
			else cout << "no\n";
		}
		else break;
	}
	return 0;
}
