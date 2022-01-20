#include <iostream>
#include <vector>
using namespace std;
int n;

int solve(vector<int> &a) {   // 재귀를 이용한 풀이
	int si = a.size();    // 현재 남아있는 에너지 구슬
	if (si == 2) return 0;    // 구슬 수가 2개면 에너지를 모을 수 없으므로 0 반환
	int re = 0;
	for (int i = 1; i < a.size() - 1; i++) {    // 첫 번째와 마지막 번째 에너지 구슬은 고를 수 없으므로 범위 지정
		int sum = a[i + 1] * a[i - 1];
		vector<int> b(a);   // b = 예비 a벡터
		b.erase(b.begin() + i);    // 해당 위치에 있던 에너지 구슬을 제거
		sum += solve(b);    // 에너지 구슬이 2개가 될 때까지 재귀
		if (re < sum) re = sum;   // 최댓값 구하기
	}
	return re;
}
int main() {
	cin >> n;
	vector<int> a(n);   // n개의 공간을 할당받은 a벡터
	for (int i = 0; i < n; i++) cin >> a[i];
	cout << solve(a);
	return 0;
}
