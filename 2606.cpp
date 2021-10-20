#include <iostream>       //dfs로 구현
#include <vector>
using namespace std;
int n, m, re = 0;
vector<int> a[101];
bool v[101];

void dfs(int x) {
	v[x] = true;
	for(int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if(!v[y]){
			dfs(y);         //탐색했는데 감염되어있으면 감염 pc 1대 추가
			re++;
		} 
	}
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		a[from].push_back(to);
		a[to].push_back(from);
	}
	
	dfs(1);         //1번 컴퓨터 기준으로 감염된 pc 수를 구하는 문제이니 dfs(1)
	cout << re;
	return 0;
}
