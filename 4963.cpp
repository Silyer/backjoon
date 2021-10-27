#include <iostream>
#include <cstring>
using namespace std;
int w, h;
int a[51][51];
bool v[51][51];
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};   //상하좌우, 대각선 4곳
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

void dfs(int y, int x) {
	v[y][x] = true;
	for(int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx >= 0 && nx < w && ny >= 0 && ny < h) {
			if(a[ny][nx] == 1 && !v[ny][nx]) dfs(ny, nx);
		}
	}
}

int main() {
	while(1){
		int re = 0;
		cin >> w >> h;	
		if(w == 0 && h == 0) return 0;
		for(int i = 0; i < h; i++) {
			for(int j = 0; j < w; j++) cin >> a[i][j];
		}
		for(int i = 0; i < h; i++) {
			for(int j = 0; j < w; j++) {
				if(a[i][j] == 1 && !v[i][j]) {  //땅이고 방문 안한 곳이면 섬의 개수 추가, 이후 
					re++;
					dfs(i, j);
				}
			}
		}
		cout << re << '\n';
		memset(a, 0, sizeof(a));      //다 썼으면 초기화
		memset(v, false, sizeof(v));
	}
	
	return 0;
}
