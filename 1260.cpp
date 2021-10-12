#include <iostream>       //인접 행렬
#include <queue>
using namespace std;
int n, m, v;
queue<int> q;
int e[1001][10001] = {0};
bool check_d[1001] = {0};
bool check_b[1001] = {0};

void bfs(int x) {
	q.push(1);
	check_b[1] = true;  //큐에 넣을 때 방문함을 알림, 시작점
	cout << x << ' ';
	
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		
		for(int i = 1; i <= n; i++) {
		    if(e[x][i] == 1 && check_b[i] == false) {
		    	q.push(i);
	 			check_b[i] = true;
    			cout << i << ' ';
			}
		}
	}
}
void dfs(int x) {
  check_d[x] = true;
  cout << x << ' ';
  for(int i = 1; i <= n; i++) {
    if(e[x][i] == 1 && check_d[i] == false) dfs(i);
  }
}
int main() {
	cin >> n >> m >> v;
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		e[a][b] = 1;
		e[b][a] = 1;
	}
	dfs(v);
	cout << '\n';
	bfs(v);
	return 0;
}

