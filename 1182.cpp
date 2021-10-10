#include <iostream>     //비트마스크를 이용
#include <vector>
using namespace std;

int main() {
	int n, s, re = 0;
	cin >> n >> s;
	vector<int> a(n, 0);
	for(int i = 0; i < n; i++) cin >> a[i];
	
	for(int i = 1; i < (1 << n); i++) {       //공집합 제외 -> i는 1부터, 전체 집합 = (1 << n) - 1이므로 1 << n까지
		int sum = 0;                            //만약 n이 13이면 비트 집합 = {0, 2, 3}
		for(int j = 0; j < n; j++) {            //전체 수열 중 있는 비트일 시 sum에 추가
			if(i & (1 << j)) sum += a[j];
		}
		if(sum == s) re++;
	}
	cout << re;
	return 0;
}
