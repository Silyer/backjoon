#include <iostream>
#include <vector>
#include <string>
using namespace std;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
vector<bool> v(26);

int solve(vector<string> &a, int x, int y) {    // bfs 길찾기 알고리즘 참고
	int re = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < a.size() && ny >= 0 && ny < a[0].size()) {
			if (v[a[nx][ny] - 'A'] == false) {
				v[a[nx][ny] - 'A'] = true;
				int go = solve(a, nx, ny);
				if (re < go) re = go;
				v[a[nx][ny] - 'A'] = false;
			}
		}
	}
	return re + 1;
}
int main() {
	int r, c;
	cin >> r >> c;
	vector<string> a(r);
	for (int i = 0; i < r; i++) cin >> a[i];
	v[a[0][0] - 'A'] = true;    // 첫번째 글자는 방문
	cout << solve(a, 0, 0);
	return 0;
}
