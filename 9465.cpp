#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, re;
		cin >> n;
		vector<vector<int>> a(2, vector<int>(n + 1, 0));
		vector<vector<int>> d(2, vector<int>(n + 1, 0));
		for(int i = 0; i < 2; i++) for(int j = 1; j <= n; j++) cin >> a[i][j];    //0~1은 직접 선언
		
		d[0][0] = 0;
		d[1][0] = 0;
		d[0][1] = a[0][1];
		d[1][1] = a[1][1];
		
		for(int i = 2 ; i <= n; i++) {
			d[0][i] = max(d[1][i - 2], d[1][i - 1]) + a[0][i];    //0번째 줄 수에서 인접하지 않는 전 칸(i - 1, i - 2) 중 최댓값 더한것
			d[1][i] = max(d[0][i - 2], d[0][i - 1]) + a[1][i];    //1번째 줄 수에서 인접하지 않는 전 칸(i - 1, i - 2) 중 최댓값 더한것
		}
		re = max(d[0][n], d[1][n]);   //0번째, 1번째 스티커를 고른 것 중 어떤 것이 최댓값인가?
		cout << re;
	}
	return 0;
}
