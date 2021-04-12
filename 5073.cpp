#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	while(1){
		int a[3] = {0};
		for(int i = 0; i < 3; i++) cin >> a[i];
		if(a[0] == 0 && a[1] == 0 && a[2] == 0) return 0;
		sort(a, a + 3);
		if(a[2] >= a[0] + a[1]) cout << "Invalid\n";
		else {
			if(a[0] == a[1] && a[1] == a[2]) cout << "Equilateral\n";
			else if (a[0] == a[1] || a[1] == a[2]) cout << "Isosceles\n";
			else if(a[0] != a[1] && a[1] != a[2]) cout << "Scalene\n";
		}
	}
	return 0;
}
