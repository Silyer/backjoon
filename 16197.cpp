#include <iostream>
#include <string>
using namespace std;
int n, m;
string a[20];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int go(int c, int x1, int y1, int x2, int y2) {   // c = 버튼을 누른 횟수, 이하 좌표
	if (c == 11) return -1;   // 10번 넘어가면 안되므로
	bool fall1 = false, fall2 = false;
	if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= m) fall1 = true;   // 각 동전이 떨어지는 위치에 있으면 true 반환
	if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= m) fall2 = true;
	if (fall1 && fall2) return -1;    // 두 동전이 같이 떨어지면 -1 변환
	if (fall1 || fall2) return c;   // 두 동전 중 하나만 떨어지면 c 반환
	int re = -1;
	for (int i = 0; i < 4; i++) {   // x1이 nx1로 이동함
		int nx1 = x1 + dx[i];
		int ny1 = y1 + dy[i];
		int nx2 = x2 + dx[i];
		int ny2 = y2 + dy[i];
		if (0 <= nx1 && nx1 < n && 0 <= ny1 && ny1 < m && a[nx1][ny1] == '#') {   // 범위 내에 한해서 이동했는데 그 곳이 벽이면 그대로
			nx1 = x1;
			ny1 = y1;
		}
		if (0 <= nx2 && nx2 < n && 0 <= ny2 && ny2 < m && a[nx2][ny2] == '#') {
			nx2 = x2;
			ny2 = y2;
		}
		int t = go(c + 1, nx1, ny1, nx2, ny2);    // 버튼 한 번 눌렀으므로  c + 1, 위치 이동 후 재귀
		if (t == -1) continue;
		if (re == -1 || re > t) re = t;
	}
	return re;
}

int main() {
	cin >> n >> m;
	int x1, y1, x2, y2;
	x1 = y1 = x2 = y2 = -1;   // 아직 위치하지 않았으므로 -1 좌표로 지정
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'o') {   // 동전이 해당 위치에 있으면
				if (x1 == -1) {   // 1번째 동전 위치 저장
					x1 = i;
					y1 = j;
				}
				else {    // 2번째 동전 위치 저장
					x2 = i;
					y2 = j;
				}
				a[i][j] = '.';  // 저장한 동전의 위치는 빈 칸으로 변환
			}
		}
	}
	cout << go(0, x1, y1, x2, y2);
	return 0;
}

