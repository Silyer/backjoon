#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	long long re = 0;
	cin >> n;
	long long d[101][11] = {0};
	d[1][0] = 0;
	for(int i = 1; i < 10; i++) d[1][i] = 1;  // d[1] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	for(int i = 2; i <= n; i++) {
		d[i][0] = d[i - 1][1] % 1000000000; // 끝자리가 0이면 1만, 9이면 8만 해당
		d[i][9] = d[i - 1][8] % 1000000000;
		for(int j = 1; j < 9; j++) d[i][j] = (d[i - 1][j - 1] + d[i - 1][j + 1]) % 1000000000;  // 이 외엔 앞, 뒷자리까지 더하기
	}
	for(int i = 0; i < 10; i++) {
		re += d[n][i];
	}
	cout << re % 1000000000;
	return 0;
}
