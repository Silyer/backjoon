#include <iostream>
#include <stack>
using namespace std;

int main() {
	int a[3][4] = {0};
	for(int i = 0; i < 3; i++) {
		int c = 0;
		
		for(int j = 0; j < 4; j++ ){
			cin >> a[i][j];
			if(a[i][j] == 0) c++;
		}
		if(c == 1) cout << "A\n";
		else if (c == 2) cout << "B\n";
		else if (c == 3) cout << "C\n";
		else if (c == 4) cout << "D\n";
		else if (c == 0) cout << "E\n";
	}
	return 0;
}
