#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n + 1, 0), d(n + 1, 0);                                       // a = 입력받은 포도주 배열, d = 최댓값 배열
	for(int i = 1; i <= n; i++) cin >> a[i];
	d[1] = a[1];                                                                //일단 첫번째 배열의 최댓값은 무조건 1번째 포도주 배열, 
	d[2] = a[1] + a[2];                                                         //두번째도 마찬가지로 1 + 2번째
	for(int i = 3; i <= n; i++) {
		d[i] = max(d[i - 3] + a[i - 1] + a[i], max(d[i - 2] + a[i], d[i - 1]));   //그 이상은 3번 연속 마시면 안되므로 x o o, o x o, o o x순으로 최댓값 검사
	}
	cout << d[n];
	return 0;
}
