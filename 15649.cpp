#include <iostream>
using namespace std;
bool vi[10];	//이 수가 방문을 했는가?
int arr[10];	//결과 배열

//깊이 우선 탐색 방법으로 백트래킹.
void dfs(int n, int m, int d) {	//d는 깊이 변수
	if(d == m) {	// m - 1까지 방문을 한다음 그 다음 깊이가 m이랑 같으면 수열 출력 
		for(int i = 0; i < m; i++) cout << arr[i] << " ";
		cout << '\n';
		return;
	}
	
	for(int i = 0; i < n; i++) {
		if(vi[i]) continue;	//방문을 한 수라면 건너뛰기
		vi[i] = true;		//그 외 방문을 했으니 true
		arr[d] = i + 1;		//수열에 d번째 수 i + 1을 넣는다. (i가 0부터 시작하기에)
		dfs(n, m, d + 1);	//마치면 재귀. 깊이 1층 더 내리기
		vi[i] = false;		//함수의 호출이 끝나면 d번재 수 i + 1 넣는 과정을 끝냈으니 초기화
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	dfs(n, m, 0);
	return 0;
}
