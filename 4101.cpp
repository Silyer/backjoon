#include <iostream>
#include <cmath>
using namespace std;

int main() {
	while(1) {
	int n, m;
	cin >> n >> m;
	if(n == 0 && m == 0) return 0;
	if(n > m) cout << "Yes\n";
	else cout << "No\n";
	}

	
	return 0;
}
