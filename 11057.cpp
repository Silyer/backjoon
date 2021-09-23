#include <iostream>
#include <vector>
using namespace std;

long long mod = 10007;
int main() {
	int n, re = 0;
	cin >> n;
	
	vector<vector<long long>> d(n + 1, vector<long long>(10, 1));
	for(int i = 1; i < n; i++) {
		for(int j = 1; j < 10; j++)	d[i][j] = (d[i][j - 1] + d[i - 1][j]) % mod;    //점화식
	}
	for(int i = 0; i < 10; i++) re += (d[n - 1][i] % mod);
	cout << re % mod;
	return 0;
}
/*
d[0] = 1 1 1 1 1 1 1 1 1 1
d[1] = 1 2 3 4 5 6 7 8 9 10
d[2] = 1 3 6 10 15 21 28 36 45 55
d[3] = 1 4 10 20 35 ...
d[n][p] = d[n][p - 1] + d[n - 1][p]

d[2] - 
0(d[1])							10
1(d[1] - 0)						9
2(d[1] - 0, 1)					8
3(d[1] - 0, 1, 2)				7
4(d[1] - 0, 1, 2, 3) ...		6	

d[3] - 
0(d[2])															55
1(d[2] - 0(d[1])												45
2(d[2] - 1(d[1] - 0))											36
3(d[2] - 1(d[1] - 0) - 2(d[1] - 0, 1))							28
4(d[2] - 1(d[1] - 0) - 2(d[1] - 0, 1) - 3(d[1] - 0, 1, 2)) ...	21
																15
																10
																6
																3
																1 */
