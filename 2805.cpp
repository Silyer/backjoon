#include <iostream>            
#include <vector>
using namespace std;

int main() {
	long long n, m, st = 1, end = 0, re = 0;
	cin >> n >> m;
	
	vector<long long> t(n, 0);
	for(int i = 0; i < n; i++) {
		cin >> t[i];
		if(end < t[i]) end = t[i];
	}
	
	while(st <= end) {					//이분 탐색
		long long mid = (st + end) / 2, cut = 0;
		for(int i = 0; i < n; i++){
			if(t[i] > mid) cut += t[i] - mid;
		} 
		
		if(cut >= m) {
			if(re < mid) re = mid;
			st = mid + 1;
		}
		else end = mid - 1;
	}
	cout << re;
	return 0;
}
