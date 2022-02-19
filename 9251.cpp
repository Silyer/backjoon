#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int t = 0;
	string s1, s2;
	cin >> s1 >> s2;
	int d[1001][1001];
	for (int i = 1; i <= s2.size(); i++) {
		for (int j = 1; j <= s1.size(); j++) {
			if (s2[i - 1] == s1[j - 1]) 
				d[i][j] = d[i - 1][j - 1] + 1;
			else
				d[i][j] = max(d[i - 1][j], d[i][j - 1]);
		}
	}
	cout << d[s2.size()][s1.size()];
	return 0;
}
