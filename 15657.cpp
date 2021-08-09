#include <iostream>
#include <algorithm>
using namespace std;
int arr[10];
int num[10];
void dfs(int n, int m, int d, int s) {    //문제가 비내림차순 : s(tart) 변수를 넣어 따로 증가시키기
	if(d == m) {
		for(int i = 0; i < m; i++) cout << num[arr[i]] << " ";
		cout << '\n';
		return;
	}
	
	for(int i = s; i < n; i++) {
		arr[d] = i;
		dfs(n, m, d + 1, i);
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
