#include <iostream>             //이분 그래프, 정점을 두 그룹으로 나누되 같은 그룹의 정점끼리는 간선으로 연결 x
#include <vector>
#include <queue>
using namespace std;

vector<int> a[20001];           //인접 리스트로 구현
int group[20001] = {0};         //group은 check 함수와 유사. 0, 1, 2로 구성됨, 0 = 방문x, 1 = 그룹 1, 2 = 그룹 2

void dfs(int x, int g) {
  group[x] = g;
  for(int i = 0; i < a[x].size(); i++) {
    int y = a[x][i];
    if(group[y] == 0) dfs(y, 3 - g);  //3 - g = g가 1이였으면 2로, 2였으면 1로
  }
}

int main() {
	int k;
	cin >> k;
  
	while(k--) {
		int V, E;
		cin >> V >> E;
    
		for(int i = 1; i <= V; i++) {   //새 테스트 케이스일 시 리스트와 방문여부 초기화
			a[i].clear();
			group[i] = 0;
		}
    
		for(int i = 0; i < E; i++) {    //인접 리스트 생성
			int u, v;
			cin >> u >> v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
    
		for(int i = 1; i <= V; i++) {
			if(!group[i]) dfs(i, 1);      //i번째 정점이 방문을 안했을 시 그룹 1에 넣고 탐색
		}
    
		bool ok = true;                           //이분 리스트의 조건을 충족하는가?
		for(int i = 1; i <= V; i++) {             //모든 정점이 이분 리스트의 조건을 충족하는지 확인
			for(int j = 0; j < a[i].size(); j++) {
				int t = a[i][j];
				if(group[i] == group[t]) ok = false;  //i번째 정점과의 간선을 통해 인접한 정점이 같은 그룹일 경우 false 반환 
			}
		}
    
		if(ok) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}
