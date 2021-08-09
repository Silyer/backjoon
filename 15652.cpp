#include <iostream>
using namespace std;

int arr[10];
void dfs(int n, int m, int d, int s) {
	if(d == m) {
		for(int i = 0; i < m; i++) cout << arr[i] << " ";
		cout << '\n';
		return;
	}
	
	for(int i = s; i <= n; i++) {
		arr[d] = i;
		dfs(n, m, d + 1, i);
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	dfs(n, m, 0, 1);
	return 0;
}
