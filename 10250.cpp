#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int h, w, n;
		cin >> h >> w >> n;
		int f = n % h, r = n / h + 1;
		if(f == 0){
			cout << h;	
			r--;
		} 
		else cout << f;
		if(r / 10 == 0) cout << "0";
		cout << r << "\n";
	}
	return 0;
}
