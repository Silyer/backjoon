#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m = 0, sum = 0, max = 0;
	int f[8001] = { 0, };   // 빈도 배열
	cin >> n;
	vector<int> a;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		sum += t;
		
		f[t + 4000]++;
		if (f[t + 4000] > max) max = f[t + 4000];
		a.push_back(t);
	}
	sort(a.begin(), a.end());
	
	double avg = sum / (double)n;
	bool ok = false;
	for (int i = 0; i < 8001; i++) {    // 두 번째로 작은 수를 가려내기 위한 연산
		if (f[i] == max) {
			m = i - 4000;
			if (ok) break;
			ok = true;
		}
	}
	cout << (int)(round(avg)) << '\n';  // 반올림 함수, round함수가 double형이 나올수 있으므로 int캐스트
	cout << a[a.size() / 2] << '\n';
	cout << m << '\n';
	cout << a[a.size() - 1] - a[0];
	return 0;
}
