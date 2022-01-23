#include <iostream>
#include <cmath>
/*
하노이의 탑 규칙
이는 n = 2부터 모두 적용. n = 1이면 그냥 1 -> 3으로 이동 시 끝

1. 1번 기둥에 있던 n - 1개의 원판을 2번 기둥으로 옮긴다.
2. 1번 기둥에 있던 1개의 가장 큰 원판을 3번 기둥으로 옮긴다.
3. 2번 기둥에 있던 n - 1개의 원판을 3번 기둥으로 옮긴다.
*/
using namespace std;

void solve(int n, int st, int to, int end) {
	if (n == 1) cout << st << ' ' << end << '\n';   // 예외 : 원판이 하나밖에 없을 경우
	else {
		solve(n - 1, st, end, to);    // 하노이의 탑 규칙 1번. st(1번 기둥)에 있던 n - 1개의 원판을 end(2번 기둥)로.
		cout << st << ' ' << end << '\n';   // 하노이의 탑 규칙 2번.  st(1번 기둥)에 있던 큰 원판을 end(3번 기둥)로.
		solve(n - 1, to, st, end);    // 하노이의 탑 규칙 3번. st(2번 기둥)에 있던 n - 1개의 원판을 end(3번 기둥)로.
	}
}
int main() {
	int k;
	cin >> k;
	cout << (int)pow(2, k) - 1 << '\n';   // 모든 옮긴 횟수는 2 ^ n - 1이다. pow()형이 실수형이므로 int형으로 캐스팅
	solve(k, 1, 2, 3);
	return 0;
}
