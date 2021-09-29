#include <iostream>
using namespace std;

void star(int n, int i, int j) {
	if(i * 2 > n && j >= 2 * i - n && i >= j) cout << ' ';
	else if (n / 3 == 1) cout << '*';
	else star(n / 2, i, j);
}
int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		for(int b = n - i; b > 0; b--) cout << ' ';
		for(int j = 1; j < i * 2; j++) {
			star(n, i, j);
		}
		cout << '\n';
	}
	return 0;
}
/*
* *        (2, 2)
*****									   4	  5	   6
*     * 	(4, 2 ~ 6) 6 : i = 4 ~ 6 j = 2 ~ 6, 4 ~ 6, 6
* *   * *	(5, 4 ~ 6)
***** *****	(6, 6)		(x + n) / 2 = i // x = 2 * i - n
*           *			(7, 2 ~ 12)	12 : 7 ~ 12
* *         * *			(8, 4 ~ 12)
*****       *****		(9, 6 ~ 12)
*     *     *     * 	(10, 8 ~ 12)
* *   * *   * *   * *	(11, 10 ~ 12)
***** ***** ***** *****/
