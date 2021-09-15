#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		long long x, y;                         //int 최댓값도 범위에 들어가므로 long long 사용
		cin >> x >> y;
		
		long long d = y - x, t = 1, n = 1;
		while(t < d) {
			if(n % 2 != 0) t += n / 2 + 1;        //밑에 나와있는 수 처럼 t = n번째 증가폭 만큼 커짐
			else t += n / 2;
			if(t <= d) n++;
		}
		cout << n << '\n';
	}
	return 0;
}
/*					            	총 수	 번째 증가폭
1					                	1	  	1	  1
1 1				              		2		  2	  1
1 2 1				              	4		  3	  2
1 2 2 1				            	6		  4	  2
1 2 3 2 1			            	9		  5	  3
1 2 3 3 2 1			          	12		6	  3
1 2 3 4 3 2 1			          16		7	  4
1 2 3 4 4 3 2 1		        	20		8	  4
1 2 3 4 5 4 3 2 1	        	25		9	  5
1 2 3 4 5 5 4 3 2 1	      	30		10	5
1 2 3 4 5 6 5 4 3 2 1	      36		11  6
1 2 3 4 5 6 6 5 4 3 2 1     42		12	6
*/
