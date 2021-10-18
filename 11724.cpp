#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> a[1001];
bool check[1001];

void dfs(int x) {
  check[x] = true;
  for(int i = 0; i < a[x].size(); i++) {
    int y = a[x][i];
    if(check[y] == false) dfs(y);
  }
}

int main() {
	int n, m;
	cin >> n >> m;
	
	while(m--) {
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	int re = 0;
	for(int i = 1; i <= n; i++) {
		if(!check[i]) {     //연결되지 않은 정점이 있을경우 연결요소 하나 추가, 한 번 더 그 정점에서 
			dfs(i);
			re++;
		}
	}
	cout << re;
	return 0;
}
