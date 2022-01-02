//1697번에서 경로 추가한 문제
#include <iostream>
#include <queue>
using namespace std;

int n, k;
int parent[100001];   // 역추적 배열, i번째 위치에서 i - 1번째 위치가 어디였는지 추적해주는 배열
bool v[100001];

void path(int a, int b) {   // 경로 함수, b위치가 a위치로 갈 때까지 추적하여 할 때 마다 그 위치를 출력
	if (a != b) {
		path(a, parent[b]);
	}
	cout << b << ' ';
}
int bfs(int n, int k) {
	queue<pair<int, int>> q;
	q.push({ n, 0 });
	v[n] = true;
	while (!q.empty()) {
		int d = q.front().first;
		int t = q.front().second;
		q.pop();
		if (d == k) return t;
		if (d + 1 >= 0 && d + 1 < 100001 && !v[d + 1]) {
			q.push({ d + 1, t + 1 });
			parent[d + 1] = d;    // 방문하고자 하는 위치에 전에 있었던 위치를 저장
			v[d + 1] = true;
		}
		if (d - 1 >= 0 && d - 1 < 100001 && !v[d - 1]) {
			q.push({ d - 1, t + 1 });
			parent[d - 1] = d;
			v[d - 1] = true;
		}
		if (d >= 0 && d * 2 < 100001 && !v[d * 2]) {
			q.push({ d * 2, t + 1 });
			parent[d * 2] = d;
			v[d * 2] = true;
		}
	}
}

int main() {
	cin >> n >> k;
	cout << bfs(n, k) << '\n';
	path(n, k);
	return 0;
}
