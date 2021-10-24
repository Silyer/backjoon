#include <iostream>   
#include <queue>
using namespace std;
int m, n, re = 0;
int a[1001][1001];
int dx[] = {1, -1, 0, 0};     //상하좌우
int dy[] = {0, 0, 1, -1};
queue<pair<int, int>> q;
void bfs() {
	while(!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		for(int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx >= 0 && nx < m && ny >= 0 && ny < n) {
				if(a[ny][nx] == 0) {              //토마토가 안 익은 과일일 때만 익은 과일에서 1일 지난 만큼 증가
					a[ny][nx] = a[y][x] + 1;
					q.push({ny, nx});
				}
			}
		}
	}
}
int main() {
	cin >> m >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> a[i][j];
			if(a[i][j] == 1) q.push({i, j});      //익은 토마토일 경우 큐에 집어 넣기
		}
	}
	bfs();
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(a[i][j] == 0) {            //탐색 이후로도 안 익은 토마토가 있으면 -1 출력
				cout << -1;
				return 0;
			}
			if(re < a[i][j]) re = a[i][j];  
		}
	}
	cout << re - 1;
	return 0;
}
