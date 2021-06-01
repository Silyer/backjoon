#include <iostream>
#include <string>
using namespace std;

int main() {
	string n;
	cin >> n;
	if(n.size() == 1 && n[0] == 1 +'0'){
		cout << "NO";
	} 
	else {
		for(int i = 0; i < n.size(); i++) {
			int f = 1, b = 1;
			for(int j = 0; j <= i; j++) f *= n[j] - '0';
			for(int j = i + 1; j < n.size(); j++) b *= n[j] - '0';
			if(f == b) {
				cout << "YES";
				return 0;
			}
		}
		cout << "NO";
	}
	return 0;
}
