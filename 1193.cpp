#include <iostream>
using namespace std;

int main() {
	int x = 0, n = -1;
	cin >> x;
	while(x > 0){
		n++;
		for(int i = 0; i <= n; i++) x--;
	}								
	//14 -> 13/1 -> 11/2 -> 8/3 -> 4/4 -> -1/5 [3][1] 2/4
	//13 -> 12/1 -> 10/2 -> 7/3 -> 3/4 -> -2/5 [2][2] 3/3
	//10 -> 9/1 -> 7/2 -> 4/3 ->		   0/4 [0][3] 4/1
	//9 -> 8/1 -> 6/2 -> 3/3 ->			  -1/4 [1][2] 3/2
	//8 -> 7/1 -> 5/2 -> 2/3 -> 		  -2/4 [2][1] 2/3
	int ax = 0, ay = 0;
	if(n % 2 != 0) {
		ax = -x;
		ay = n - ax; 
	}
	else ay = -x; ax = n - ay;
	cout << ay + 1 << "/" << ax + 1;
	//x = y + 1, y = x + 1
	//[0][0]/ [1][0] [0][1] /[0][2] [1][1] [2][0]/ [3][0] [2][1] [1][2] [0][3]
	//[0][4] [1][3] [2][2] [3][1] [4][0]
	return 0;
}
