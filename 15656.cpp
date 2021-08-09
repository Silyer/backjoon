#include <iostream>
#include <algorithm>
using namespace std;
int arr[10];
int num[10];
void dfs(int n, int m, int d) {
	if(d == m) {
		for(int i = 0; i < m; i++) cout << num[arr[i]] << " ";
		cout << '\n';
		return;
	}
	
	for(int i = 0; i < n; i++) {
		arr[d] = i;
		dfs(n, m, d + 1);
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	
	for(int i = 0; i < n; i++) cin >> num[i];
	sort(num, num + n);
	dfs(n, m, 0);
	return 0;
}
