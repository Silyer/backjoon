#include <iostream>
#include <queue>
using namespace std;
int m, n, h;
int a[101][101][101];
int v[101][101][101];
int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

void bfs(int x, int y, int z) {
	v[z][y][x] = true;
	queue<pair<pair<int,int>,pair<int,int>>> q;
	q.push({x, y}, {z, 0});
	while(!q.empty()) {
		int tx = q.front().first.first;
		int ty = q.front().first.second;
		int tz = q.front().second;
		q.pop();
		for(int i = 0; i < 4; i++) {
			
		}
	}
}
int main() {
	cin >> m >> n >> h;
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < m; k++) cin >> a[j][k][i];
		}
	}

	return 0;
}
