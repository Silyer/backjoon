#include <iostream>
#include <algorithm>
using namespace std;

struct Node {   // 왼쪽, 오른쪽 자식, 순서, 깊이가 존재하는 노드 구조체
	int left;
	int right;
	int order;
	int depth;
};
Node a[10010];
int w[10010];   //루트 탐색을 목적으로한 배열
int order = 0;    //순서 변수
int le[10010], ri[10010];   //각 왼, 오른쪽 관계 배열

void inorder(int n, int d) {    //중위 순회를 이용, d = 깊이
	if (n == -1) return;
	inorder(a[n].left, d + 1);
	a[n].order = ++order;   //순서는 계속 증가
	a[n].depth = d;
	inorder(a[n].right, d + 1);
}

int main() {
	int n, x, y, z, r;  //r = root
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> z;
		a[x].left = y;
		a[x].right = z;
		if (y != -1) w[y] += 1;
		if (z != -1) w[z] += 1;
	}
	for (int i = 1; i <= n; i++) {    //무조건 루트가 1로 시작하는게 아니니 탐색 후 지정
		if (w[i] == 0) r = i;     //부모가 없는 노드이면 루트
	}

	inorder(r, 1);    //첫 번째 레벨의 너비와 깊이는 각 1
	int maxd = 0;   //깊이 최댓값
	for (int i = 1; i <= n; i++) {
		int depth = a[i].depth;
		int order = a[i].order;
		if (le[depth] == 0) le[depth] = order;  //깊이마다 제일 왼쪽에 있는 노드 구하기
		else le[depth] = min(le[depth], order);
		ri[depth] = max(ri[depth], order);    //깊이마다 제일 오른쪽에 있는 노드 구하기
		maxd = max(maxd, depth);    //제일 깊은 곳 구하기
	}

	int re= 0, re_l = 0;
	for (int i = 1; i <= maxd; i++) {   //깊이 마다 기록한 좌우 노드를 토대로
		if (re < ri[i] - le[i] + 1) {   //제일 넓은 곳의 최댓값과 그 곳의 깊이를 기록
			re = ri[i] - le[i] + 1;
			re_l = i;
		}
	}
	cout << re_l << ' ' << re;
	return 0;
}

