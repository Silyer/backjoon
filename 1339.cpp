#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
char alpha[256];  // 아스키 코드로서의 i값

int calc(vector<string> &a, vector<char> &le, vector<int> &d) {
	int m = le.size();
	int sum = 0;
	for (int i = 0; i < m; i++) alpha[le[i]] = d[i];
	for (string s : a) {    // 단어 1개 단위로 값을 계산
		int now = 0;
		for (char x : s) now = now * 10 + alpha[x];
		sum += now;
	}
	return sum;
}

int main() {
	int n;
	cin >> n;
	vector<string> a(n);    // 단어
	vector<char> le;    // 알파벳
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (char x : a[i]) le.push_back(x);
	}
	sort(le.begin(), le.end());                         //  중복 제거
	le.erase(unique(le.begin(), le.end()), le.end());

	int m = le.size();    // 서로 다른 알파벳이 m개면 큰 숫자 m개만 넣어서 조사
	vector<int> d;
	for (int i = 9; i > 9 - m; i--) d.push_back(i);
	sort(d.begin(), d.end());   // 밑에 순열 구문을 돌리기 위해 정렬

	int re = 0;
	do {
		int now = calc(a, le, d);
		if (re < now) re = now;
	} while (next_permutation(d.begin(), d.end()));
	cout << re;
	return 0;
}

