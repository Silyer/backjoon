#include <iostream>
using namespace std;
int a[500][500];
int main() {
	int n, m, r = 0;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	
	for(int i = 0; i < n; i++) {        //테트로 미노 모양들
		for(int j = 0; j < m; j++) {
			if(j + 3 < m) {                 // │모양
				int t = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i][j + 3];
				if(r < t) r = t;
			}
			if(i + 3 < n) {                 // ─모양
				int t = a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 3][j];
				if(r < t) r = t;
			}
			if(i + 2 < n && j + 1 < m) {    // L모양
				int t = a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 2][j + 1];
				if(r < t) r = t;
			}
			if(i + 2 < n && j - 1 >= 0) {   // ┘모양
				int t = a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 2][j - 1];
				if(r < t) r = t;
			}
			if(i + 2 < n && j + 1 < m) {    // ┏모양
				int t = a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i][j + 1];
				if(r < t) r = t;
			}
			if(i + 2 < n && j + 1 < m) {    // ┓모양
				int t = a[i][j] + a[i][j + 1] + a[i + 1][j + 1] + a[i + 2][j + 1];
				if(r < t) r = t;
			}
			if(i + 1 < n && j + 2 < m) {    // 누운 ┌모양
				int t = a[i][j] + a[i + 1][j] + a[i][j + 1] + a[i][j + 2];
				if(r < t) r = t;
			}
			if(i + 1 < n && j + 2 < m) {    // 누운 ┐모양
				int t = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i + 1][j + 2];
				if(r < t) r = t;
			}
			if(i + 1 < n && j + 2 < m) {    // 누운 ㄴ모양
				int t = a[i][j] + a[i + 1][j] + a[i + 1][j + 1] + a[i + 1][j + 2];
				if(r < t) r = t;
			}
			if(i - 1 >= 0 && j + 2 < m) {   // 누운 ┘모양
				int t = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i - 1][j + 2];
				if(r < t) r = t;
			}
			if(i + 2 < n && j + 1 < m) {    // └┐ 모양
				int t = a[i][j] + a[i + 1][j] + a[i + 1][j + 1] + a[i + 2][j + 1];
				if(r < t) r = t;
			}
			if(i + 2 < n && j - 1 >= 0) {   // ┌┘ 모양
				int t = a[i][j] + a[i + 1][j] + a[i + 1][j - 1] + a[i + 2][j - 1];
				if(r < t) r = t;
			}
			if(i + 1 < n && j + 2 < m) {    // ┐_모양
				int t = a[i][j] + a[i][j + 1] + a[i + 1][j + 1] + a[i + 1][j + 2];
				if(r < t) r = t;
			}
			if(i - 1 >= 0 && j + 2 < m) {   // _┌모양
				int t = a[i][j] + a[i][j + 1] + a[i - 1][j + 1] + a[i - 1][j + 2];
				if(r < t) r = t;
			}
			if(i + 2 < n && j + 1 < m) {    // ├ 모양
				int t = a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 1][j + 1];
				if(r < t) r = t;
			}
			if(i + 2 < n && j - 1 >= 0) {   // ┤ 모양
				int t = a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 1][j - 1];
				if(r < t) r = t;
			}
			if(i - 1 >= 0 && j + 2 < m) {   // ┴ 모양
				int t = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i - 1][j + 1];
				if(r < t) r = t;
			}
			if(i + 1 < n && j + 2 < m) {    // ┬ 모양
				int t = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i + 1][j + 1];
				if(r < t) r = t;
			}
			if(i + 1 < n && j + 1 < m) {    // ㅁ 
				int t = a[i][j] + a[i + 1][j] + a[i][j + 1] + a[i + 1][j + 1];
				if(r < t) r = t;
			}
		}
	}
	cout << r;
	return 0;
}
