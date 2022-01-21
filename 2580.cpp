#include <iostream>
#include <vector>
using namespace std;
int a[10][10];
bool row[10][10]; // row[i][j]일 때 i번째 행에 숫자 j가 있을 경우 true
bool col[10][10]; // col[i][j]일 때 i번째 열에 숫자 j가 있을 경우 true
bool s[10][10];   // s[i][j]일 때 i번째 정사각형 내에 숫자 j가 있을 경우 true

bool solve(int n) {
	if (n == 81) {    // 탐색하고자 하는 수가 81이 될 경우 출력 (0 ~ 80까지 있기 때문)
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) cout << a[i][j] << ' ';
			cout << '\n';
		}
		return true;
	}
	int x = n / 9;
	int y = n % 9;
	if (a[x][y] != 0) return solve(n + 1);
	else {
		for (int i = 1; i <= 9; i++) {
			if (row[x][i] == 0 && col[y][i] == 0 && s[(x / 3) * 3 + (y / 3)][i] == 0) {
				row[x][i] = true;
				col[y][i] = true;
				s[(x / 3) * 3 + (y / 3)][i] = true;
				a[x][y] = i;
				if (solve(n + 1)) return true;  
				a[x][y] = 0;  //다시 원래대로 되돌려놓기
				row[x][i] = false;
				col[y][i] = false;
				s[(x / 3) * 3 + (y / 3)][i] = false;
			}
		}
	}
	return false;
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> a[i][j];
			if (a[i][j] != 0) {   // 해당 행, 열, 3 x 3 사각형 내에 0이 없을 때
				row[i][a[i][j]] = true;  
				col[j][a[i][j]] = true;
				s[(i / 3) * 3 + (j / 3)][a[i][j]] = true;   // (i / 3) * 3 + (j / 3) = 3 * 3 사각형 내
			}
		}
	}
	solve(0);
	return 0;
}
