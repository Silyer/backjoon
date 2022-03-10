#include <iostream>
using namespace std;

int main()
{
	int n, k;
	int a[101]=  { 0, }, d[10001] = { 0, };
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];

	d[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = a[i]; j <= k; j++) d[j] = d[j] + d[j - a[i]];
	}
	cout << d[k];
	return 0;
}
/*
d[1] = 1; (1원짜리로 1 경우)
d[2] = 2; (1원짜리로 1 + 1 = 1경우, 2원짜리로 2 = 1경우. 총 2경우)
d[3] = d[3] + d[3 - x] = 3; (1원짜리로 1 + 1 + 1 = 1경우, 2원을 만드는 경우의 수로 1 + 2 = 1경우, 3원으로 1경우)
현재 x원인 동전을 가지고 있다면, 
이 동전을 이용해서 y원을 만들고 싶다면?
d[y] = d[y] + d[y- x];
*/
