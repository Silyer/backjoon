#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int n, c = 0, m = 0;
	cin >> n;
	string* s = new string[n];
	for(int i = 0; i < n; i++) cin >> s[i];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i + 1 < n) {
				swap(s[i][j], s[i + 1][j]);
				for(int a = 0; a < n; a++) {
					c = 1;
					for(int b = 1; b < n; b++) {
						if(s[a][b] == s[a][b - 1]) c++;
						else c = 1;
						if(m < c) m = c;
					}
					c = 1;
					for(int b = 1; b < n; b++) {
						if(s[b][a] == s[b - 1][a]) c++;
						else c = 1;
						if(m < c) m = c;
					}
				}
				swap(s[i][j], s[i + 1][j]);
			}
			if(j + 1 < n) {
				swap(s[i][j], s[i][j + 1]);
				for(int a = 0; a < n; a++) {            //정답이긴 하나 동일한 함수가 위에도 있어 따로 함수를 만들어야함.
					c = 1;
					for(int b = 1; b < n; b++) {
						if(s[a][b] == s[a][b - 1]) c++;
						else c = 1;
						if(m < c) m = c;
					}
					c = 1;
					for(int b = 1; b < n; b++) {
						if(s[b][a] == s[b - 1][a]) c++;
						else c = 1;
						if(m < c) m = c;
					}
				}
				swap(s[i][j], s[i][j + 1]);
			}
		}
	}
	cout << m;
	return 0;
}
