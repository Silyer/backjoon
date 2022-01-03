#include <iostream>   //bfs에 dp를 곁들인 문제
#include <queue>
#include <cstring>
using namespace std;

int s;
int d[2000][2000];    //d[이모지 개수][클립보드]가 re가 됨, d[][] = n이면 n만큼의 시간이 흘렀음. n = -1이면 방문을 아예안함
int main() {
	cin >> s;
	int re = -1;                //-1 : 방문 x, 그 외엔 방문함
	memset(d, -1, sizeof(d));   //-1로 모두 초기화
	queue<pair<int, int>> q;    //q({이모지 개수, 클립보드 이모지 개수})
	q.push({ 1, 0 });           //이미 1개의 이모티콘이 생성되어 있으므로
	d[1][0] = 0;
	while (!q.empty()) {
		int e = q.front().first;
		int c = q.front().second;
		q.pop();
		if (d[e][e] == -1) {     //복사하는 연산
			q.push({ e, e });
			d[e][e] = d[e][c] + 1;
		}
		if (d[e + c][c] == -1 && e + c <= s) {    //클립보드에 있는 이모지 개수만큼 붙여넣는 연산
			q.push({ e + c, c });
			d[e + c][c] = d[e][c] + 1;
		}
		if (d[e - 1][c] == -1 && e - 1 >= 0) {    //이모지를 하나씩 삭제하는 연산
			q.push({ e - 1, c });
			d[e - 1][c] = d[e][c] + 1;
		}
	}
	for (int i = 0; i <= s; i++) {    //결과 최솟값 연산
		if (d[s][i] != -1) {
			if (re == -1 || re > d[s][i]) re = d[s][i];
		}
	}
	cout << re;
	return 0;
}
