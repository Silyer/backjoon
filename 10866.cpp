#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, f = 10000, b = 10000;
	cin >> n;
	
	int d[20000] = {0};
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if(s == "push_front") {
			int x;
			cin >> x;
			d[--f] = x;
		}
		else if(s == "push_back") {
			int x;
			cin >> x;
			d[b++] = x;
		}
		else if(s == "pop_front") {
			if(b - f <= 0) cout << -1 << '\n';
			else cout << d[f++] << '\n';
		}
		else if(s == "pop_back") {
			if(b - f <= 0) cout << -1 << '\n';
			else cout << d[--b] << '\n';
		}
		else if(s == "size") cout << b - f << '\n';
		else if(s == "empty") {
			if(b - f == 0) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if(s == "front") {
			if(b - f <= 0) cout << -1 << '\n';
			else cout << d[f] << '\n';
		}
		else if(s == "back") {
			if(b - f <= 0) cout << -1 << '\n';
			else cout << d[b - 1] << '\n';
		}
	}
	return 0;
}
