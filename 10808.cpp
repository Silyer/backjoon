#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	int a[26] = {0};
	cin >> s;
	for(int i = 0; i < s.size(); i++) {
		for(int j = 0; j < 26; j++)	if(s[i] == 'a' + j) a[j]++;
	}
	for(int i = 0; i < 26; i++) cout << a[i] << " ";
	return 0;
}
