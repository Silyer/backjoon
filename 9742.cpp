#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string s;
	int n;
	while (cin >> s >> n) {
		cout << s << ' ' << n << " = ";
		int c = 0;
		do {
			c++;
			if (c == n) {
				cout << s << '\n';
				break;
			}
		} while (next_permutation(s.begin(), s.end()));
		if (c != n) cout << "No permutation" << '\n';
	}
	return 0;
}
