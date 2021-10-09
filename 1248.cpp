#include <iostream>
#include <string>
using namespace std;

int n;
int s[10][10];
int re[10];

bool ok() {
	for(int i = 0; i < n; i++) {
		int sum = 0;
		for(int j = i; j < n; j++) {
			sum += re[j];
			if(s[i][j] == 0) {
				if(sum != 0) return false;
			}
			else if (s[i][j] > 0) {
				if(sum <= 0) return false;
			}
			else if (s[i][j] < 0) {
				if(sum >= 0) return false;	
			} 
		}
	}
	return true;
}

bool solve(int idx) {
	if(idx == n) return ok();
	if(s[idx][idx] == 0) {
		re[idx] = 0;
		return solve(idx + 1);
	}
	for(int i = 1; i <= 10; i++) {
		re[idx] = s[idx][idx] * i;
		if(solve(idx + 1)) return true;
	}
	return false;
}

int main() {
	int k = 0;
	cin >> n;
	string ss;
	cin >> ss;
	for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
			if(ss[k] == '0') s[i][j] = 0;
			else if(ss[k] == '+') s[i][j] = 1;
			else s[i][j] = -1;
			k++;
		}
	}
	solve(0);
	for(int i = 0; i < n; i++) printf("%d ", re[i]);
	return 0;
}
