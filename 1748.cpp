#include <iostream>
using namespace std;

int main() {
	int n, l = 1;
	long long r = 0;
	cin >> n;
	for(int i = 1; i <= n; i *= 10) {               // i ~ i * 10 - 1 (자릿수마다)
		int end = i * 10 - 1;
		if(end > n) end = n;                          // 예외 : end가 n보다 클 경우 n에 맞추기
		r += (long long)(end - i + 1) * l;
		l++;
	}
	cout << r;
	return 0;
}
