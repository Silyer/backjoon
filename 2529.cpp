#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int n;
char k[10];
vector<string> re;
bool ok[10];
bool comp(string s) {							
	for(int i = 0; i < n; i++) {
		if(k[i] == '<') if (s[i] > s[i + 1]) return false;
		if(k[i] == '>') if (s[i] < s[i + 1]) return false;
	}
	return true;
}

void solve(int idx, string num) {
	if(idx == n + 1) {
		if(comp(num)) {
			re.push_back(num);
		}
		return;
	}
	for(int i = 0; i <= 9; i++) {
		if(ok[i]) continue;
		ok[i] = true;
		solve(idx + 1, num + to_string(i));
		ok[i] = false;
	}
}
int main() {
	cin >> n;
	for(int i = 0; i < n; i++) cin >> k[i];
	solve(0, "");
	auto p = minmax_element(re.begin(), re.end());
    cout << *p.second << '\n';
    cout << *p.first << '\n';
	return 0;
}
