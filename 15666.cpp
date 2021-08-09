#include <iostream>
#include <algorithm>
using namespace std;
int arr[10];
int num[10];
void dfs(int n, int m, int d, int s) {
	if(d == m) {
		for(int i = 0; i < m; i++) cout << arr[i] << " ";
		cout << '\n';
		return;
	}
	int b = -1;
	for(int i = s; i < n; i++) {
		if(i == 0 || b != num[i]){
			b = num[i];
			arr[d] = num[i];
			dfs(n, m, d + 1, i);
		}
		
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	
	for(int i = 0; i < n; i++) cin >> num[i];
	sort(num, num + n);
	dfs(n, m, 0, 0);
	return 0;
}
