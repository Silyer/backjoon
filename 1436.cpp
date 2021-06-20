//test
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int n, d = 1666, m[10001] = {0};
	cin >> n;
	for(int i = 0; i < 1; i++) {
		int si = 0;
		string s = to_string(d);
		cout << "d = " << d << "\n";
		for(int j = 0; j < s.size() - 2; j++) {
			for(int k = j; k < j + 3; k++) {
				cout << "s[" << k << " = " << s[k] << "\n"; 
				if(s[k] == '6') si++;
			}
			cout << "si = " << si << "\n";
			if(si >= 3) {
				m[i] = d;
				break;
			}
			else si = 0;
		}
		d++;
	}
	cout << m[0] << " " << m[1];
	return 0;
}
