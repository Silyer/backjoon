#include <iostream>
#include <stack>
using namespace std;

int main() {
	int a[5][4] = {0}, s[5] = {0}, max = 0, c = 0;
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 4; j++ ){
			cin >> a[i][j];
			s[i] += a[i][j];
		}
	}
	for(int i = 0; i < 5; i++) {
		if(max < s[i]){
			max = s[i]; 
			c = i + 1;
		} 
	}
	cout << c << " " << max;
	return 0;
}
