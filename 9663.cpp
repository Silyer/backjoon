#include <iostream>   // 재귀를 이용한 풀이
#include <string>
using namespace std;
int n;
bool a[15][15];
bool check_col[15];   // 해당 열에 퀸이 공격 안되는지
bool check_dig[40];   // 해당 대각선에 퀸이 공격 안되는지 (row + col)
bool check_dig2[40];  // 해당 역대각선에 퀸이 공격 안되는지 (row - col + n)

bool check(int row, int col) {    // 해당 row행 col열에 퀸이 들어올 수 있는가?
	if (check_col[col]) return false;
	if (check_dig[row + col]) return false;
	if (check_dig2[row - col + n]) return false;
	return true;
}
int calc(int row) {
	if (row == n) return 1;
	int c = 0;
	for (int col = 0; col < n; col++) {
		if (check(row, col)) {
			check_dig[row + col] = true;    // 퀸을 놓았다는 것을 다른 함수를 위해 처리
			check_dig2[row - col + n] = true;
			check_col[col] = true;
			a[row][col] = true;   // 퀸을 해당 위치에 둠
			c += calc(row + 1);    // 다음 행에 대한 재귀 실행
			check_dig[row + col] = false;   // 해놓은 것들 다시 초기화
			check_dig2[row - col + n] = false;
			check_col[col] = false;
			a[row][col] = false;
		}
	}
	return c;
}
int main() {
	cin >> n;
	cout << calc(0);    // 0번 행부터 퀸을 놓아줌.
	return 0;
}

