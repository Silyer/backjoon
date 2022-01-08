#include <iostream>   // 가중치를 0, 1로 두어 덱과 bfs를 이용해 풀었음, 이 때 가중치 1은 벽을 부수고 이동했다임
#include <deque>
#include <cstring>
using namespace std;
int n, m;
int a[101][101];
int v[101][101];      // -1 = 방문 x, 이외는 방문함. 가중치에 따라 수는 늘어난다
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int main() {
	cin >> m >> n;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			a[i][j] = s[j] - '0';
		}
	}
	deque<pair<int, int>> d;    // (x, y) 덱 생성
	memset(v, -1, sizeof(v));   // v배열 모두 -1로 초기화
	d.push_back({ 0, 0 });      // 시작 좌표 설정
	v[0][0] = 0;                // 시작 좌표를 방문했기에 0으로 설정

	while (!d.empty()) {
		int x = d.front().first;
		int y = d.front().second;
		d.pop_front();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (v[nx][ny] == -1) {    // 방문을 안한 좌표인 경우
					if (a[nx][ny] == 0) {   // 방문 좌표 가중치가 0일 시 이전에 방문했던 좌표랑 동일시하게 수를 반환
						v[nx][ny] = v[x][y];
						d.push_front({ nx, ny });
					}
					else {                  // 방문 좌표 가중치가 1일 시 이전에 방문했던 좌표에서 1추가
						v[nx][ny] = v[x][y] + 1;
						d.push_back({ nx, ny });
					}
				}
			}
		}
	}
	cout << v[n - 1][m - 1];
	return 0;
}

