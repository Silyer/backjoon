#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[51][51], b[51][51];

void ch(int x, int y) {   // 3 * 3 사각형에 있는 숫자를 바꾸는 함수
	for (int i = x - 1; i <= x + 1; i++) {
		for (int j = y - 1; j <= y + 1; j++) a[i][j] = 1 - a[i][j];
	}
}

int main() {
	int n, m, re = 0;
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) scanf("%1d", &a[i][j]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) scanf("%1d", &b[i][j]);
	}
	for (int i = 0; i < n - 2; i++) {   // n - 1, n번째 수는 어차피 이 반복문에 의해 바뀌므로 연산에 투자하지 않음
		for (int j = 0; j < m - 2; j++) {
			if (a[i][j] != b[i][j]) {
				re += 1;
				ch(i + 1, j + 1);
			}
		}
	}
	for (int i = 0; i < n; i++) {     // 연산을 끝낸 후로도 a와 b가 다르다면 -1 
		for (int j = 0; j < m; j++) {
			if (a[i][j] != b[i][j]) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << re;
	return 0;
}
