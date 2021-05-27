#include <iostream>
#include <algorithm>
using namespace std;
bool pri(int n) {
	if (n < 2) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, c = 0, m = 10000, re, p[10001] = {0};
		cin >> n;
		for(int i = 2; i < n; i++) if(pri(i)) p[c++] = i;
		for(int i = 0; i < c; i++){
			if(pri(n - p[i])){
				if(p[i] > n - p[i]) {
					if(m > p[i] - (n - p[i])){
						m = p[i] - (n - p[i]);
						re = p[i];
					}
				}
				else {
					if(m > (n - p[i]) - p[i]){
						m = (n - p[i]) - p[i];
						re = p[i];	
					} 
				}
			}
		}
		cout << re << " " << n - re << "\n";
	}
	return 0;
}
