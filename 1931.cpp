#include <iostream>   // 그리디 알고리즘을 이용한 풀이
#include <vector>
#include <algorithm>
using namespace std;

struct Meet {   // 회의 시작과 끝을 나타내는 구조체
	int start, end;
};

bool cmp(Meet& u, Meet& v) {     // 시작과 끝이 같은 회의가 중복되는 예외를 대비한 비교 함수 : 1 1 / 1 2 / 2 2 / 2 2
	if (u.end == v.end) return u.start < v.start;
	else return u.end < v.end;
}

int main() {
	int n;
	cin >> n;
	vector<Meet> a(n);
	for (int i = 0; i < n; i++) cin >> a[i].start >> a[i].end;
	sort(a.begin(), a.end(), cmp);
	int p = 0, re = 0;    // p = 회의가 끝난 시간, 아직 시작도 안했으니 0으로 초기화, re = 회의 횟수 
	for (int i = 0; i < a.size(); i++) {
		if (p <= a[i].start) {
			p = a[i].end;
			re += 1;
		}
	}
	cout << re;
	return 0;
}
