#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int l, kx, ky, rx, ry;
int a[301][301];    // 방문 x = -1, 나이트 위치 = 0, 이후 최소 경로
int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};    //나이트가 이동하는 경우의 수
int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
queue<pair<int, int>> q;

void bfs(int y, int x) {
	q.push({x, y});
	a[y][x] = 0;
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx >= 0 && nx < l && ny >= 0 && ny < l) {
				if(a[ny][nx] == -1) {
					q.push({nx, ny});
					a[ny][nx] = a[y][x] + 1;
				}
			}
		}
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> l;
		cin >> kx >> ky;  // 현재 나이트의 위치
		cin >> rx >> ry;  // 목적지 위치
		memset(a, -1, sizeof(a)); // 체스판을 모두 -1로 초기화
		bfs(ky, kx);    // 현재 나이트의 위치에서부터 탐색
		cout << a[ry][rx] << '\n';  // 목적지의 최소 경로 시간 
		memset(a, -1, sizeof(a));
	}
	return 0;
}
