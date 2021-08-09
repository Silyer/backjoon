#include <iostream>
using namespace std;

int arr[10];                    //결과 수열
void dfs(int n, int m, int d) { //d는 깊이 변수
	if(d == m) {                  //d = m일 때 결과 수열 출력
		for(int i = 0; i < m; i++) cout << arr[i] << " ";
		cout << '\n';
		return;
	}
	
	for(int i = 0; i < n; i++) {  
		arr[d] = i + 1;
		dfs(n, m, d + 1);
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	dfs(n, m, 0);
	return 0;
}
