  #include <iostream>       //bfs를 통해 구현
#include <string>
#include <queue>
using namespace std;

int n, m;
int a[101][101];
bool v[101][101];
int re[101][101] = {0};       //미로에서 1이고 길 한번 지나갈때 마다 1씩 증가
int dx[] = {1, -1, 0, 0};     //x좌표에서 1, -1씩 증가
int dy[] = {0, 0, 1, -1};     //y좌표에서 1, -1씩 증가

void bfs(int x, int y) {
	v[x][y] = true;
	re[x][y]++;
	queue<pair<int, int>> q;
	q.push({x, y});
	while(!q.empty()) {
		int tx = q.front().first;
		int ty = q.front().second;
		q.pop();
		for(int i = 0; i < 4; i++) {
			int nx = tx + dx[i], ny = ty + dy[i];           //nx, ny = 지금 방문하려는 x좌표, y좌표 
			if(nx >= 0 && nx < n && ny >= 0 && ny < m) {    //nx, ny가 범위 내에 있고
				if(a[nx][ny] && !v[nx][ny]) {                 //방문하려는 좌표가 1이고 아직 방문을 안했을 경우
					v[nx][ny] = true;                           //너비 우선 탐색
					q.push({nx, ny});
					re[nx][ny] = re[tx][ty] + 1;                //지금 지나려는 곳은 지나갔던 좌표에 1을 더한다
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for(int j = 0; j < m; j++) {
			a[i][j] = s[j] - '0';
		}
	}
	bfs(0, 0);
	cout << re[n - 1][m - 1];
	return 0;
}
