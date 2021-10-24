#include <iostream>       //7576 3차원 버전
#include <queue>
using namespace std;
int m, n, h, re = 0;
int a[101][101][101];
int dx[] = {1, -1, 0, 0, 0, 0};       //상하좌우전후
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};
queue<pair<pair<int, int>, int>> q;
void bfs() {
	while(!q.empty()) {
		int x = q.front().first.second;   
		int y = q.front().first.first;
		int z = q.front().second;
		q.pop();
		for(int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];
			if(nx >= 0 && nx < m && ny >= 0 && ny < n && nz >= 0 && nz < h) {
				if(a[ny][nx][nz] == 0) {          //범위 내에 있고, 익지 않은 토마토라면 익은지 n일 된 토마토에 1일을 더해줌
					a[ny][nx][nz] = a[y][x][z] + 1;
					q.push({{ny, nx}, nz});
				}
			}
		}
	}
}
int main() {
	cin >> m >> n >> h;
	for(int k = 0; k < h; k++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				cin >> a[i][j][k];
				if(a[i][j][k] == 1) q.push({{i, j}, k});      //특정 장소에 익은 토마토가 있을 경우 큐에 삽입
			}
		}
	}
	bfs();
	for(int k = 0; k < h; k++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(a[i][j][k] == 0) {       //탐색 이후로도 익지 않은 토마토가 있다면 -1 출력
					cout << -1;
					return 0;
				}
				if(re < a[i][j][k]) re = a[i][j][k];
			}
		}
	}

	cout << re - 1;
	return 0;
}
