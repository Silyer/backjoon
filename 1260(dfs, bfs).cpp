#include <iostream>
#include <cstring>    //memset
#include <queue>
using namespace std;
int n, m, v;
queue<int> q;         //bfs queue

int e[1001][1001];    //인접 행렬
bool check[1001];     //방문 여부

void dfs(int x) {
  check[x] = true;
  cout << x << ' ';
  for(int i = 1; i <= n; i++) {
    if(e[x][i] == 1 && check[i] == false) dfs(i);
  }
}

void bfs(int x) {
	q.push(x);        //큐에 x넣고 방문 표시
	check[x] = true;
	
	while(!q.empty()) {
		x = q.front();
		q.pop();
		cout << x << ' ';
		for(int i = 1; i <= n; i++) {
		    if(e[x][i] == 1 && check[i] == 0) {
		    	check[i] = true;
		    	q.push(i);
			}
		}
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
	memset(check, false, sizeof(check));  //check 함수 초기화
	bfs(v);
	return 0;
}
