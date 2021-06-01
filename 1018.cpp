#include <iostream>
using namespace std;
//입력된 보드에 8*8체스판 을 떼가서 고쳐야하는 정사각형의 최소갯수 구하는 문제
int main() {
	int n, m, maxn = 0, minn = 50, maxm = 0, minm  = 50, ren, rem;
	cin >> n >> m;
	char bo[51][51] = {0};
	int re[51][51] = {0};
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> bo[i][j];
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(i == 0 || j == 0) {
				if(bo[i][j] == bo[i][j + 1])
					re[i][j] = 1;
				else if(bo[i][j] == bo[i + 1][j])
					re[i][j] = 1;
			}
			else {
				if(bo[i][j] == bo[i][j - 1])
					re[i][j] = 1;
				else if(bo[i][j] == bo[i - 1][j])
					re[i][j] = 1;	
			}
			
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(re[i][j] == 1) {
				cout << i << " " << j << "\n"; //반례 측정용
				if(maxn < i) maxn = i;
				if(minn > i) minn = i;
				if(maxm < j) maxm = j;
				if(minm > j) minm = j;
			}
		}
	}
	ren = maxn - minn;
	rem = maxm - minm;
	if(ren > rem) cout << ren;
	else cout << rem;
	return 0;
}
