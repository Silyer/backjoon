#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, re = 0; 
	cin >> n;
	vector<int> a(n + 1, 0), d(n + 1, 0), dd(n + 1, 0);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) {                                                                  //가장 긴 증가하는 함수
		d[i] = 1;
		for(int j = 0; j < n; j++) if(a[j] < a[i] && d[i] < d[j] + 1) d[i] = d[j] + 1;
	}
	for(int i = n - 1; i >= 0; i--) {                                                             //가장 긴 감소하는 함수
		dd[i] = 1;
		for(int j = i + 1; j < n; j++) if(a[j] < a[i] && dd[i] < dd[j] + 1) dd[i] = dd[j] + 1;
	}
	for(int i = 0; i < n; i++) if(re < d[i] + dd[i] - 1) re = d[i] + dd[i] - 1;                   //이들끼리 합쳐서 나오는 
	cout << re;
	return 0;
}
