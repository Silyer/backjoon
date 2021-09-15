#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, t = 1;
	cin >> n;

	vector<int> x(n), y(n), l(n);                                       //x = 입력 받은 좌표, y = 정렬한 x좌표, l = 압축 좌표
	for(int i = 0; i < n; i++){
		cin >> x[i];
		y[i] = x[i];
	} 
	sort(y.begin(), y.end());
	
	l[0] = y[0];
	for(int i = 1; i < n; i++) if(y[i] != y[i - 1]) l[t++] = y[i];      //중복되지 않은 y좌표를 l좌표에 압축

	for(int i = 0; i < n; i++) {                                        //이분 탐색을 이용하여 x좌표에 압축 좌표 대입하는데 시간 단축
		int le = 0, ri = t;                                              
		while(le <= ri) {
			int mid = (le + ri) / 2;
			if(x[i] < l[mid]) ri = mid - 1;
			else if(x[i] > l[mid]) le = mid + 1;
			else {
				cout << mid << ' ';
				break;
			}
		}
	}
	return 0;
}
