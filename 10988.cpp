#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	int n = 0;
	cin >> s;
	for(int i = 0; i < s.size() / 2; i++) if(s[i] != s[s.size() - i - 1])n++;
	if(n > 0) cout << "0";
	else cout << "1";
	return 0;
}
