#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	while(1) {
		int a[3] = {0}, l = 0;
		for(int i = 0; i < 3; i++) cin >> a[i];
		if(a[0] == 0 && a[1] == 0 && a[2] == 0) return 0;
		sort(a, a + 3);
		l = a[2] * a[2];
		if(l == a[0] * a[0] + a[1] * a[1]) cout << "right\n";
		else cout << "wrong\n";
	}
	
	
	return 0;
}
