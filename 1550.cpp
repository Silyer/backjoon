#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	string s;
	int n = 0;
	cin >> s;
	for(int i = s.size() - 1;  i >= 0; i--) {
		if(s[i] == 'A') n += 10 * pow(16, s.size() - i - 1);
		else if (s[i] == 'B') n += 11 * pow(16, s.size() - i - 1);
		else if (s[i] == 'C') n += 12 * pow(16, s.size() - i - 1);
		else if (s[i] == 'D') n += 13 * pow(16, s.size() - i - 1);
		else if (s[i] == 'E') n += 14 * pow(16, s.size() - i - 1);
		else if (s[i] == 'F') n += 15 * pow(16, s.size() - i - 1);
		else n += (s[i] - '0') * pow(16, s.size() - i - 1);
	}
	cout << n;
	return 0;
}
