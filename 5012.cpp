#include <iostream>
#include <vector>     //최단 거리 bfs 구현
#include <queue>
using namespace std;
int f, s, g, u, d;
vector<int> dx;
int a[1000001] = {0};   //버튼을 누른 경로
bool v[1000001];        //이 층에 방문했는가
queue<int> q;

void bfs(int x) {
	v[x] = true;
	q.push(x);
	while(!q.empty()) {
		x = q.front();
		q.pop();    
		for(int i = 0; i < 2; i++) {      //u, d로 이루어진 벡터 dx로 올라갈지 내려갈지 정함
			int nx = x + dx[i];
			if(nx > 0 && nx <= f && !v[nx]) {   //다음에 갈 좌표가 범위 내에 있고 방문 안한 층일 시 
				v[nx] = true;                     //방문 표시, 큐에 nx 넣고, 방문할 경로에 지금의 경로에 +1
				q.push(nx);
				a[nx] = a[x] + 1;
			}
		}
	}
}

int main() {
	cin >> f >> s >> g >> u >> d;
	dx.push_back(u);
	dx.push_back(d * -1);       //내려가는 것이므로 -1 곱
	
	bfs(s);     //내가 있는 s층에서 탐색
	if(v[g]) cout << a[g];    //g층에 방문했다면 경로가 완성된 a[g] 출력
	else cout << "use the stairs";    //못했다면 해당 문구 
	return 0;
}
