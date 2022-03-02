#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int gcd(int a, int b) {   // 최대공약수 알고리즘
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int main()
{
	int n, r;
	int a[101] = { 0, };
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	int m = a[1] - a[0];
	for (int i = 2; i < n; i++) m = gcd(m, a[i] - a[i - 1]);    // 나머지가 모두 같은 수가 될려면 각 항의 차에 대한 최대공약수를 구한 후 그 수의 약수를 구해야함.
	vector<int> v;
	for (int i = 1; i <= m; i++) {
		if (m % i == 0) {
			if (i > m / i) break;   // 절반을 넘어가면 더 이상 연산을 할 필요가 없으므로 생략
			v.push_back(i);
			if (i == m / i) break;    // 제곱근일 경우에도 한 번 생략
			v.push_back(m / i);
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == 1) continue;    // 1은 포함하지 않으므로 출력 생략
		else cout << v[i] << ' ';
	}
	return 0;
}
