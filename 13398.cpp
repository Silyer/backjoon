#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, re = -1000;
	cin >> n;
	vector<int> a(n + 1, 0), d(n + 1, 0), d2(n + 1, 0);                    //a = 입력받은 수열, d = i까지의 연속합, d2 = i부터의 연속합
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) {
		d[i] = a[i];
		if(i != 0 && d[i] < d[i - 1] + a[i]) d[i] = d[i - 1] + a[i];
	}
	for(int i = n - 1; i >= 0; i--) {
		d2[i] = a[i];
		if(i != n - 1 && d2[i] < d2[i + 1] + a[i]) d2[i] = d2[i + 1] + a[i];
	}
	
	for(int i = 0; i < n; i++) if(re < d[i]) re = d[i];                     //굳이 제거를 안해도 될 때의 연속합 최댓값
	for(int i = 1; i < n - 1; i++) if(re < d[i - 1] + d2[i + 1]) re = d[i - 1] + d2[i + 1];   //제거를 할 때 i번째를 제외한 연속합 최댓값

	cout << re;
	return 0;
}
