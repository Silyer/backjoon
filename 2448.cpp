#include <iostream>
using namespace std;
char a[10000][10000];
void star(int n, int i, int j) {
	if(n == 3) {						//n = 3일때 나오는 삼각형 출력. (규칙으로 안됨)
		a[i][j] = '*';
		a[i + 1][j - 1] = '*';
		a[i + 1][j + 1] = '*';
		a[i + 2][j - 2] = '*';
		a[i + 2][j - 1] = '*';
		a[i + 2][j] = '*';
		a[i + 2][j + 1] = '*';
		a[i + 2][j + 2] = '*';
	}
	else {							//n이 그 이상이면 
		star(n / 2, i, j);				//꼭대기에서
		star(n / 2, i + n / 2, j - n / 2);		//왼쪽 꼭짓점에서
		star(n / 2, i + n / 2, j + n / 2);		//오른쪽 꼭짓점으로 재귀
	}
}

int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n * 2 - 1; j++) {
			a[i][j] = ' ';
		}
	}
	star(n, 0, n - 1);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n * 2 - 1; j++) {
			cout << a[i][j];
		}
		cout << '\n';
	}
	return 0;
}
