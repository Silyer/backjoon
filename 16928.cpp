#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, m, t = n + m;
	int d[101], next[101]; // d = 이동 배열(-1 = 방문 x), next = 뱀, 사다리, 일반 칸 배열
	cin >> n >> m;
	
	for (int i = 1; i <= 100; i++) {    // 모든 칸이 일단 일반 칸이라 가정(이 위치에 도달했을 때 변동 없음), 거리를 -1(방문 안함)로 초기화 
		next[i] = i;
		d[i] = -1;
	}
  
	int t = n + m;
  
	while (t--) {   // 사다리와 뱀 입력을 받음
		int x, y;
		cin >> x >> y;
		next[x] = y;
	}
  
	d[1] = 0;     // 시작점이 1이므로 1부터 bfs 시작
	queue<int> q;
	q.push(1);
  
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 1; i <= 6; i++) {
			int nx = x + i;   // 주사위에 따른 이동
			if (nx > 100) continue;   // 범위를 벗어날 시 이동 x
			nx = next[nx];    // 사다리와 뱀의 영향을 받았는지?
			if (d[nx] == -1) {    // 방문 안한 곳은 이전에 방문했던 횟수에 +1, 탐색
				d[nx] = d[x] + 1;
				q.push(nx);
			}
		}
	}
	cout << d[100];   // 100번째에 나온 최솟값 출력
	return 0;
}
