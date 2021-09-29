#include <iostream>                   //나중에
using namespace std;
char a[10000][10000];
void star(int n, int i, int j) {
	
}

int main() {
	int n;
	cin >> n;
	if(n == 1) cout << '*';
	else {
		for(int i = 0; i < n * 3; i++) {
			for(int j = 0; j < n * 3; j++) {
				a[i][j] = ' ';
			}
		}
	}
	

	return 0;
}
/*()
(0, 0 ~ 8) (2, 2 ~ 6) (4, 4) (6, 2 ~ 6) (8, 0 ~ 8)
(0 ~ 8, 0) (2 ~ 6, 2) (4, 4) (2 ~ 6, 6) (0 ~ 8, 8)
(0 ~ 12, 0) (2 ~ 10, 2) (4 ~ 8, 4) (6, 6) (4 ~ 8, 8) (2 ~ 10, 10) (0 ~ 12, 12)*/
