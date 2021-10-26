#include <iostream>
#include <cstring>
using namespace std;
int n, re = 0;
int a[101][101];
int v[101][101];
int dx[] = {1, -1, 0, 0};   //상하좌우
int dy[] = {0, 0, 1, -1};

void dfs(int y, int x, int t) {
	v[y][x] = true;
	for(int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx >= 0 && nx < n && ny >= 0 && ny < n) {    //범위 내, 방문할 곳이 t보다 높은 높이에 방문하지 않은 곳이면 
			if(a[ny][nx] > t && !v[ny][nx]) dfs(ny, nx, t); 
		}
	}
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	for(int r = 0; r < 101; r++) {    //비가 r이하인 지점까지 잠길정도로 내림
		int z = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(a[i][j] > r && !v[i][j]) {   //잠기지 않는 높이이고 방문 하지 않은 곳일시
					dfs(i, j, r);                 //탐색 후 구역 수 ++
					z++;
				}
			}
		}
		if(re < z) re = z;        //최대 구역 선정
		memset(v, false, sizeof(v));
	}
	cout << re;
	return 0;
}
