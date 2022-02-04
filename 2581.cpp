#include <iostream>
#include <vector>
using namespace std;

int main() {
	int m, n, sum = 0;
	cin >> m >> n;
	vector<int> p;    // 소수 벡터
	for (int i = m; i <= n; i++) {
		if (i == 1) continue;   // 1은 소수가 아니므로 건너뛰기
		bool ok = true;   // 소수인지 판별
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {   // 해당 수가 2부터 시작해서 나뉘는 점이 있을 경우 소수가 아닌걸로 판별
				ok = false;
				break;
			}
		}
		if (ok) p.push_back(i);   // 소수가 맞을 경우 해당 벡터에 추가
	}
	if (p.size() == 0) {    // 소수 벡터에 하나도 포함되지 않았을 경우 -1 출력
		cout << -1;
		return 0;
	}
	for (int i = 0; i < p.size(); i++) sum += p[i];
	cout << sum << '\n' << p[0];
	return 0;
}
