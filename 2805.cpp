#include <iostream>             //아직 미완
#include <vector>
using namespace std;

int main() {
	long long n, m, st = 1, end = 0, min = 9999999999;
	cin >> n >> m;
	
	vector<long long> t(n, 0);
	for(int i = 0; i < n; i++) {
		cin >> t[i];
		if(end < t[i]) end = t[i];
	}
	
	while(st <= end) {
		long long mid = (st + end) / 2, cut = 0;
		for(int i = 0; i < n; i++){
			cut += t[i] - end;
			if(cut < 0) cut = 0;
		} 
		if(cut >= m) {
			if(min > mid) min = mid;
			st = mid + 1;
		}
		else end = mid - 1;
	}
	cout << min;
	return 0;
}
