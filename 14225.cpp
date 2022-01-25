#include <iostream>   // 비트마스크를 이용하여 풀이
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	int s[21];
	bool v[2000010] = { false };    // 주어진 수열로 조합할 수 있는 수인지?
	for (int i = 0; i < n; i++) cin >> s[i];
	for (int i = 0; i < (1 << n); i++) {    // 모든 부분집합 완전 탐색
		int sum = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) sum += s[j];    // 탐색한 숫자들을 모두 sum에 누적
		}
		v[sum] = true;  // sum에 있는 수는 방문한 것으로.
	}
	for (int i = 1;; i++) {
		if (!v[i]) {    // 방문하지 않은 수가 있다면 그것이 
			cout << i;
			break;
		}
	}
	return 0;
}
