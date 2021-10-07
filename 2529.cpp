#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int n;
char k[10];
vector<string> re;
bool ok[10];
bool comp(char a, char b, char c) {
	if(c == '<') if (a > b) return false;
	if(c == '>') if (a < b) return false;
	return true;
}

void solve(int idx, string num) {
	if(idx == n + 1) {
		re.push_back(num);
		return;
	}
	for(int i = 0; i <= 9; i++) {
		if(ok[i]) continue;
		if(idx == 0 || comp(num[idx - 1], i + '0', k[idx - 1])) {
			ok[i] = true;
			solve(idx + 1, num + to_string(i));
		}
	}
}
int main() {
	cin >> n;
	for(int i = 0; i < n; i++) cin >> k[i];
	solve(0, "");
  //다른 건 다 끝냈는데 최소, 최댓값 출력 구현 
	return 0;
}
