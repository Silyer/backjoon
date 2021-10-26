#include <iostream>
#include <cstring>
using namespace std;
int n, m, t = 0, re;
int a[301][301];
bool v[301][301];
int dx[] = {1, -1, 0, 0};   // 상하좌우
int dy[] = {0, 0, 1, -1};

void melt() {   t 때의 빙산의 
	int me[301][301] = {0};   // me : t - 1때의 빙하에 비해 t때의 빙하의 높이가 감소하는 정도
  
	for(int i = 0; i < n; i++) {      //현 좌표에서 사방에 0이 있을 시 있는 개수만큼 빙산 높이 차감
		for(int j = 0; j < m; j++) {
			if(a[i][j] > 0) {
				if(i - 1 >= 0 && a[i - 1][j] == 0) me[i][j]++;
				if(i + 1 < n && a[i + 1][j] == 0) me[i][j]++;
				if(j - 1 >= 0 && a[i][j - 1] == 0) me[i][j]++;
				if(j + 1 < m && a[i][j + 1] == 0) me[i][j]++;
			}
		}
	}
  
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {    // 그대로 a에 감소치 반영, 음수로 갈 경우 0으로 치환
			a[i][j] -= me[i][j];
			if(a[i][j] < 0) a[i][j] = 0;    
		}
	}
  
}

void dfs(int y, int x) {    // 빙산이 몇 개의 구역으로 나뉘어 지는지 탐색
	v[y][x] = true;
	for(int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx >= 0 && nx < m && ny >= 0 && ny < n) {
			if(a[ny][nx] > 0 && !v[ny][nx]) dfs(ny, nx);
		}
	}
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
  
	while(1) {
		t++;
		int gla = 0;    // 빙산의 개수
		bool ok = false;  // 빙산이 분리되기 전에 다 녹아 없어졌는가?
    
		for(int i = 0; i < n; i++) {    //빙산이 다 녹아 없어졌는지 체크, 그렇다면 0 출력 후 종료
			for(int j = 0; j < m; j++) {
				if(a[i][j]) ok = true;
			}
		}
    
		if(!ok) {
			cout << 0;
			return 0;
		}
    
		melt(); // t라는 시간이 흐른 만큼 녹는 빙산 
    
		for(int i = 0; i < n; i++) {        // 녹은 빙산이 2개 이상으로 분리가 되었는지 탐색
			for(int j = 0; j < m; j++) {
				if(a[i][j] > 0 && !v[i][j]) {
					gla++;
					dfs(i, j);
				}
			}
		}
    
		if(gla > 1) {   // 빙산이 분리가 되었을 경우 분리된 시점을 출력 후 종료
			cout << t;
			return 0;
		}
    
		memset(v, false, sizeof(v));    // 탐색 방문 내역 
	}
	return 0;
}
