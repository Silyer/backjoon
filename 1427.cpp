#include <iostream>     //버블 정렬
#include <vector>
using namespace std;

int main() {
	int n, t = 0;
	cin >> n;
	vector<int> a;
	while(n != 0) {
		a.push_back(n % 10);
		n /= 10;
	}
	for(int i = 0; i < a.size(); i++) {
		for(int j = 0; j < a.size(); j++) {
			if(a[i] > a[j]) {
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
	for(int i = 0; i < a.size(); i++) cout << a[i];
	return 0;
}
