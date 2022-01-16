#include <iostream>   //순열을 이용한 문제
#include <vector>
#include <algorithm>
using namespace std;
int a[101];   // 수를 모아놓은 배열
vector<int> si; // 부호를 모아놓은 배열

int main() {
	int n, max = -1000000000, min = 1000000000;

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	int pl, mi, mu, di;   // 각 덧셈, 뺄셈, 곱셉, 나눗셈
	cin >> pl >> mi >> mu >> di;  
	for (int i = 0; i < pl; i++) si.push_back(1);   // si벡터에 정수화하여 넣어줌, 사칙연산 각 1 2 3 4로
	for (int i = 0; i < mi; i++) si.push_back(2);
	for (int i = 0; i < mu; i++) si.push_back(3);
	for (int i = 0; i < di; i++) si.push_back(4);

	do {
		int t = a[0];   // 맨 첫번째 수를 넣고 
		for (int i = 0; i < si.size(); i++) {   // 이후부터 부호에 따라 값을 
			if (si[i] == 1) t += a[i + 1];
			else if (si[i] == 2) t -= a[i + 1];
			else if (si[i] == 3) t *= a[i + 1];
			else if (si[i] == 4) t /= a[i + 1];
		}
		if (max < t) max = t;
		if (min > t) min = t;
	} while (next_permutation(si.begin(), si.end()));

	printf("%d\n%d", max, min);
	return 0;
}

