#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int n, m, v;
int e[1001][10001] = {0};
bool check[1001] = {0};;

void bfs(int x) {
	queue<int> q;
	q.push(x);
	check[1] = true;
	cout << x << ' ';
	
	while(!q.empty()) {
		x = q.front();
		q.pop();
		for(int i = 1; i <= n; i++) {
		    if(e[x][i] == 1 && check[i] == 0) {
		    	q.push(i);
		    	check[i] = true;
		    	cout << i << " ";
			}
		}
	}
}

void dfs(int x) {
  check[x] = true;
  cout << x << ' ';
  for(int i = 1; i <= n; i++) {
    if(e[x][i] == 1 && check[i] == false) dfs(i);
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
	memset(check, false, sizeof(check));
	bfs(v);
	return 0;
}
