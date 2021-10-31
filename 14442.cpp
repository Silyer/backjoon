#include <iostream>   //뭔가 심각하게 문제가 있다..
#include <string>
#include <queue>
using namespace std;
int n, m, k;
int a[1001][1001];
int v[1001][1001][11];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void bfs(int x, int y, int w) {
	queue<tuple<int, int, int>> q;
	q.push({x, y, w});
	v[x][y][w] = 1;
	while(!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		w = q.front().third;
		q.pop();
		for(int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if(a[nx][ny] == 0 && v[nx][ny][w] == 0) {
					v[nx][ny][w] = v[x][y][w] + 1;
					q.push({nx, ny, w});
				}
				if(a[nx][ny] == 1 && v[nx][ny][w + 1] == 0&& w < k) {
					v[nx][ny][w + 1] = v[x][y][w] + 1;
					q.push({nx, ny, w + 1});
				}
			}
		}	
	}
	
}

int main() {
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for(int j = 0; j < m; j++) a[i][j] = s[j] - '0';
	}
	bfs(0, 0, 0);
	cout << v[n - 1][m - 1][k];
	return 0;
}
