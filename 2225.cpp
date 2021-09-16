#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//d[k][n] = sig(d[k - 1][n - a]) (0 <= i <= n)
int main() { 
	int n, k;
	cin >> n >> k;
	vector<vector<long long>> d(k + 1, vector<long long>(n + 1, 0));
	d[0][0] = 1;
	for(int i = 1; i <= k; i++) {     //i - 1를 사용해야 하기에 (0, 0)에 1을 선언 후 i = 1부터 시작
		for(int j = 0; j <= n; j++) {   //j - l이여도 0, sig(d[k - 1][n - a])충족 가능 여기서 a가 l이 되줌
			for(int l = 0; l <= j; l++) {
				d[i][j] += d[i - 1][j - l];
				d[i][j] %= 1000000000;
			}
		}
	}
	cout << d[k][n];
}
