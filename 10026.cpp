#include <iostream>  //미완성
#include <string>
using namespace std;
char a[101][101];
bool v[101][101];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
void dfs(int x, int y) {
	v[x][y] = true;
	for(int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if(a[nx][ny] == 'R' && a[x][y] == '' ) {
				if(!v[nx][ny]) dfs(nx, ny);
			}
			if(a[nx][ny] == 'B' && a[x][y] == '' ) {
				if(!v[nx][ny]) dfs(nx, ny);
			}
			if(a[nx][ny] == 'G' && a[x][y] == '' ) {
				if(!v[nx][ny]) dfs(nx, ny);
			}
		}
	}
}
void dfs_b(int x, int y) {
	v[x][y] = true;
	for(int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if(a[nx][ny] == 'R' && a[x][y] == '' ) {
				if(!v[nx][ny]) dfs(nx, ny);
			}
			if(a[nx][ny] == 'B' && a[x][y] == '' ) {
				if(!v[nx][ny]) dfs(nx, ny);
			}
			if(a[nx][ny] == 'G' && a[x][y] == '' ) {
				if(!v[nx][ny]) dfs(nx, ny);
			}
		}
	}
}
int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			a[i][j] = s[j];
		}
	}
	for(int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
