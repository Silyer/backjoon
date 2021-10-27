#include <iostream>
#include <cmath>
using namespace std;
int n, m;
char a[51][51];
bool v[51][51];
int re[51][51];     // 알파벳마다 탐색한 수만큼 값 증가
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int y, int x) {
	v[y][x] = true;
	for(int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx >= 0 && nx < m && ny >= 0 && ny < n) {
			if(a[ny][nx] == a[y][x] && !v[ny][nx]) {    // 방문할 알파벳이 현재 알파벳과 같고 방문 안한 경우
				re[ny][nx] = re[y][x] + 1;                // re배열에 1증가 시켜주고 탐색
				dfs(ny, nx);
			}
		}
	}
}

int main() {
	cin >> n >> m;
  
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for(int j = 0; j < m; j++) a[i][j] = s[j];
	}
  
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(re[i][j] == 0 && !v[i][j]) dfs(i, j);    // 아직 탐색 안한 알파벳이고 방문 안했을 경우 탐색 시작
		}
	}
  
	for(int i = 0; i < n; i++) {      // 사이클이 되는지?
		for(int j = 0; j < m; j++) {
			for(int k = 0; k < 4; k++) {    // 현재 위치에서 사방을 기준으로
				int nx = j + dx[k];
				int ny = i + dy[k];
				if(nx >= 0 && nx < m && ny >= 0 && ny < n) {
					if(re[i][j] - re[ny][nx] >= abs(3) && a[ny][nx] == a[i][j]) {   // 알파벳이 4번 이상 인접하고, 현 위치와 같은 알파벳
						cout << "Yes" << '\n';
						return 0;
					}
				}
			}
		}
	}
  
	cout << "No" << '\n';
	return 0;
}
