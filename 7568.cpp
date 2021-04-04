#include <iostream>
using namespace std;

int main() {
	int n = 0;
	cin >> n;
	int x[50] = {0}, y[50] = {0}, r[50] = {0};
	for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
	for(int i = 0; i < n; i++) {
		int re = 1;
		for(int j = 0; j < n; j++) if(i != j) if(x[i] < x[j] && y[i] < y[j]) re++;
		r[i] = re;
	}
	for(int i = 0; i < n; i++) cout << r[i] << " ";
	return 0;
}
