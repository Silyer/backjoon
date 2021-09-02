#include <iostream>
#include <vector>
using namespace std;

int main() {
	long long k, n, st = 1, end = 0, max = 0;           //이분 탐색 이용, st = 1인 이유 = mid가 0이 되는 것을 방지
	cin >> k >> n;
	
	vector<long long> l(k, 0);
	for(int i = 0; i < k; i++) {
		cin >> l[i];
		if(end < l[i]) end = l[i];
	}
	
	while(st <= end) {                                  //이분 탐색 
		long long mid = (st + end) / 2, div = 0;
		for(int i = 0; i < k; i++) div += l[i] / mid;
		if(div >= n) {
			if(max < mid) max = mid;
			st = mid + 1;
		}
		else end = mid - 1;
	}
	cout << max;
	return 0;
}
