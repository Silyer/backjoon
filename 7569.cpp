#include <iostream>		//보류
#include <queue>
using namespace std;
int m, n, h;
int a[101][101][101];
bool v[101][101][101];
int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

int bfs(int x, int y, int z) {
	v[z][y][x] = true;
	queue<pair<pair<int,int>,pair<int,int>>> q;
	q.push({x, y}, {z, 0});
	while(!q.empty()) {
		int tx = q.front().first.first;
		int ty = q.front().first.second;
		int tz = q.front().second;
		q.pop();
		for(int i = 0; i < 6; i++) {
			int nx = tx + dx[i];
			int ny = ty + dy[i];
			int nz = tz + dz[i];
			
			if(nx >= 0 && nx < n && ny >= 0 && ny < n && nz >= 0 && nz < n) {
				if(!v[nx][ny][nz] && a[nx][ny][nz] == 0) {
					q.push({nx, ny}, {nz, 0});
					v[nx][ny][nz] = true;
					
				}
			}
		}
	}
}
int main() {
	cin >> m >> n >> h;
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < m; k++){
				cin >> a[j][k][i];
				if(a[j][k][i] == -1) v[j][k][i] = true;
				else if(a[j][k][i] == 1) q.push({j, k}, {i, 0});
			} 
		}
	}

	return 0;
}
