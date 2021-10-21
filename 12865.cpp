#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int w[101] = {0}, v[101] = {0};
	int d[101][100001];
	
	for(int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}
	
	for(int i = 1; i <= n; i++) {           // i번째 물건들을 통하여 무게를 가방 무게 j까지 만들기 
		for(int j = 1; j <= k; j++) {
			if(j >= w[i]) {                     // 넣고자 하는 물건이 가방 무게에 들어가지는가?
				d[i][j] = max(d[i - 1][j], d[i - 1][j - w[i]] + v[i]);  //되면 탐색을 통해서 넣고 안넣고를 정함
			}
			else d[i][j] = d[i - 1][j];         //안되면 안넣는 것을 택함
		}
	}
	cout << d[n][k];
	return 0;
}

