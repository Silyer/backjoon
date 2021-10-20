#include <iostream>
using namespace std;
int m, n, k;
int a[51][51] = {0};
int dx[] = {1, -1, 0, 0};       //현재 맵 좌표에서 x좌표를 1, -1씩 이동
int dy[] = {0, 0, 1, -1};       //현재 맵 좌표에서 y좌표를 1, -1씩 이동
bool v[51][51];

void dfs(int x, int y) {
	v[x][y] = true;
	for(int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];     //nx = 현재 방문한 x좌표, ny = 현재 방문한 y좌표
		if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if(a[nx][ny]) {
				if(!v[nx][ny]) dfs(nx, ny);         //배추가 있는 자리이고 방문을 아직 안했다면 탐색
			}
		}
	}
}

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int re = 0;
		cin >> m >> n >> k;
		for(int i = 0; i < k; i++) {      //x가 가로, y가 세로이기 때문에 a[y][x]에 집어넣기
			int x, y;
			cin >> x >> y;
			a[y][x] = 1;
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(a[i][j]) {
					if(!v[i][j]) {
						re++;
						dfs(i, j);        //배추가 있는 자리인데 방문을 아직 안했다면 벌레 개수 추가, 배추있는 자리가 다 연결되어있고 방문할 때까지 탐색
					}
				}
			}
		}
		cout << re << '\n';
		
		for(int i = 0; i < 50; i++) {       //사용했던  초기화
			for(int j = 0; j < 50; j++){
				a[i][j] = 0;
				v[i][j] = false;
			} 
		}
	}
	
	return 0;
}
