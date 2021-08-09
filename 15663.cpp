#include <iostream>
#include <algorithm>
using namespace std;
bool vi[10];
int arr[10];
int num[10];
void dfs(int n, int m, int d) {               // n과 m (5)문제랑 유사. 중복 되는 수만 처리하면 됨
	if(d == m) {
		for(int i = 0; i < m; i++) cout << arr[i] << " ";
		cout << '\n';
		return;
	}
	int b = -1;                                 // b라는 변수 삽입. 
	for(int i = 0; i < n; i++) {                
		if(!vi[i] && (i == 0 || b != num[i])){    // 같은 조건에 b랑 중복되는 수가 있으면 그대로 패스 하는 조건문
			b = num[i];
			arr[d] = num[i];
			vi[i] = true;
			dfs(n, m, d + 1);
			vi[i] = false;
		}		
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
