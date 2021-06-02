#include <iostream>
using namespace std;

int main() {
	int n, m, c[101] = {0}, re = 0, t = 0;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> c[i];
	}
	for(int i = 0; i < n - 2; i++) {
		for(int j = i + 1; j < n - 1; j++) {
			for(int k = j + 1; k < n; k++) {
				t = c[i] + c[j] + c[k];
				if(t > re && t <= m) re = t;
			}
		}
	}
	cout << re;
	return 0;
}
