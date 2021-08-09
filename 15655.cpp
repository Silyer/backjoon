#include <iostream>
#include <algorithm>
using namespace std;
bool vi[10];
int arr[10];
int num[10];
void dfs(int n, int m, int d, int s) {
	if(d == m) {
		for(int i = 0; i < m; i++) cout << num[arr[i]] << " ";
		cout << '\n';
		return;
	}
	
	for(int i = s; i <= n; i++) {
		if(vi[i]) continue;
		vi[i] = true;
		arr[d] = i - 1;
		dfs(n, m, d + 1, i + 1);
		vi[i] = false;
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	
	for(int i = 0; i < n; i++) cin >> num[i];
	sort(num, num + n);
	dfs(n, m, 0, 1);
	return 0;
}
