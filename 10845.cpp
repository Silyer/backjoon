#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, f = 0, r = 0;
	cin >> n;
	int q[10001] = {0};
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if(s == "push") {
			int x;
			cin >> x;
			q[r++] = x;
		}
		else if(s == "pop") {
			if(r - f <= 0) cout << -1 << '\n';
			else cout << q[f++] << '\n';
		}
		else if(s == "size") {
			cout << r - f << '\n';
		}
		else if(s == "empty") {
			if(r - f <= 0) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if(s == "front") {
			if(r - f <= 0) cout << -1 << '\n';
			else cout << q[f] << '\n';
		}
		else if(s == "back") {
			if(r - f <= 0) cout << -1 << '\n';
			else cout << q[r - 1] << '\n';
		}
		
	}
	return 0;
}
