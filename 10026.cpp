#include <iostream>
#include <cstring>
using namespace std;
int n;
char a[101][101];
int v[101][101]; // 정상 : 0 미방문, 1 R, 2 B, 3 G	색약 : 0미방문, 1RG, 2B
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int x, int y, int c) {		//적록색약이 아닌 사람
	v[x][y] = c;	//방문여부를 색으로 표현, 0은 미방문, 1~3은 색
	for(int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];	//nx = 방문할 x좌표, ny = 방문할 y좌표
		if(nx >= 0 && nx < n && ny >= 0 && ny < n) {	//방문한 곳이 방문할 곳과 같은 색이고, 아직 방문 안한 경우 탐색
			if(a[nx][ny] == 'R' && c == 1) {
				if(!v[nx][ny]) dfs(nx, ny, 1);
			}
			if(a[nx][ny] == 'B' && c == 2) {
				if(!v[nx][ny]) dfs(nx, ny, 2);
			}
			if(a[nx][ny] == 'G' && c == 3) {
				if(!v[nx][ny]) dfs(nx, ny, 3);
			}
		}
	}
}

void dfs_b(int x, int y, int c) {	//적록색약인 사람, R과 G를 구분 못하므로 c = 1로 통일
	v[x][y] = c;
	for(int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if(nx >= 0 && nx < n && ny >= 0 && ny < n) {
			if((a[nx][ny] == 'R' || a[nx][ny] == 'G') && c == 1) {
				if(!v[nx][ny]) dfs_b(nx, ny, 1);
			}
			if(a[nx][ny] == 'B' && c == 2) {
				if(!v[nx][ny]) dfs_b(nx, ny, 2);
			}
		}
	}
}
int main() {
	
	cin >> n;
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			a[i][j] = s[j];
		}
	}
	int re = 0, re_b = 0;
	for(int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(a[i][j] == 'R' && !v[i][j]) {	//구역 탐색시 새로운 색이고 방문 안한경우 re++
				re++;
				dfs(i, j, 1);
			}
			if(a[i][j] == 'B' && !v[i][j]) {
				re++;
				dfs(i, j, 2);
			}
			if(a[i][j] == 'G' && !v[i][j]) {
				re++;
				dfs(i, j, 3);
			}
		}
	}
	for(int i = 0; i < n; i++) memset(v[i], 0, sizeof(int)* n);	//방문 여부 배열 
	for(int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if((a[i][j] == 'R' || a[i][j] == 'G') && !v[i][j]) {
				re_b++;
				dfs_b(i, j, 1);
			}
			if(a[i][j] == 'B' && !v[i][j]) {
				re_b++;
				dfs_b(i, j, 2);
			}
		}
	}
	cout << re << ' ' << re_b;
	return 0;
}
