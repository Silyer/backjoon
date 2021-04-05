#include <iostream>
using namespace std;

int main() {
	int n, nc = 0, c = 0;
	int a[101] = {0};
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		if(a[i] == 1) c++;
		else nc++;
	}
	if(c > nc) cout << "Junhee is cute!";
	else cout << "Junhee is not cute!";
	return 0;
}
