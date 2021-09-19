#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, re = 0;
	cin >> n;
	vector<vector<int>> d(n + 1, vector<int>(3, 1));

	for(int i = 2; i <= n; i++) {
		d[i][0] = (d[i - 1][0] + d[i - 1][1] + d[i - 1][2]) % 9901;       //사자가 i번 줄에 모두 없을 경우
		d[i][1] = (d[i - 1][0] + d[i - 1][2]) % 9901;                     //사자가 i번 줄에 왼쪽에만 있을 경우
		d[i][2] = (d[i - 1][0] + d[i - 1][1]) % 9901;                     //사자가 i번 줄에 쪽에만 있을 경우
	}
	cout << (d[n][0] + d[n][1] + d[n][2]) % 9901;
	return 0;
}
