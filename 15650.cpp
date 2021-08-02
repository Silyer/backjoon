#include <iostream>
using namespace std;
bool vi[10];	//이 수가 방문을 했는가?
int arr[10];	//결과 배열

void dfs(int n, int m, int d, int s) {	//d는 깊이 변수, s는 오름차순 변수
	if(d == m) {	// m - 1까지 방문을 한다음 그 다음 깊이가 m이랑 같으면 수열 출력 
		for(int i = 0; i < m; i++) cout << arr[i] << " ";
		cout << '\n';
		return;
	}
	
	for(int i = s; i < n; i++) {
		arr[d] = i + 1;		//수열에 d번째 수 i + 1을 넣는다. (i가 0부터 시작)
		dfs(n, m, d + 1, i + 1);	//마치면 재귀
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	dfs(n, m, 0, 0);
	return 0;
}
