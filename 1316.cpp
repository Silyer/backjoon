#include <iostream>
#include <string>
using namespace std;
int main() {
	int n, re = 0;
	cin >> n;
	while(n--) {
		string s;
		cin >> s;
		int c = 0;
		for(int i = 0; i < s.size(); i++) {
			for(int j = 0; j < s.size(); j++) {
				if(s[i] == s[j]) {
					if(i == 0)
						if(i != j && i != j + 1)c++;
					else if(i == s.size() - 1)
						if(i != j - 1 && i != j)c++;
					else
						if(i != j - 1 && i != j && i != j + 1) c++;
				}
			}
		}
		//cout << ((s.size() - 3) * s.size()) + 2 << " " << c << " ";
		if(c == 0 || c == s.size() - 1) re++;
	}
	cout << re;
	return 0;
}
