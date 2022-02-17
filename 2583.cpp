#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n, k, c; // c = 해당 영역에 몇 개의 눈금이 있는지
int a[101][101];
bool v[101][101];

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void dfs(int x, int y) {    // 방문 안했고 눈금이 안된 구역일 시 탐색
	v[x][y] = true;
	c++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
			if (!v[nx][ny]) dfs(nx, ny);
		}
	}
}

int main() {
	vector<int> re;   // c를 저장하는 배열
	cin >> m >> n >> k;
	while (k--) {
		int lx, ly, rx, ry;
		cin >> lx >> ly >> rx >> ry;
		for (int i = ly; i < ry; i++) {
			for (int j = lx; j < rx; j++) {
				a[i][j] = 1;
				v[i][j] = true; // 빗금 되어있는 구역은 방문한 것으로 가정
			}
		}
	}
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 0 && v[i][j] == false) {
				c = 0;
				dfs(i, j);
				re.push_back(c);    // 각 구역마다 몇 개의 눈금이 있는지 저장
			}
		}
	}
	sort(re.begin(), re.end());
	cout << re.size() << '\n';
	for (int i = 0; i < re.size(); i++) cout << re[i] << ' ';
	return 0;
}
