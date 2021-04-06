#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
	int n, m;
	int l, r, mid;
	int a[100001] = {0}, b;
	
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
  //a 배열 입력 후 정렬
	
	cin >> m;
	for(int i = 0; i < m; i++) {
		cin >> b;
		r = n - 1;
		l = 0;
		while(l <= r) { //이진 탐색
			mid = (r + l) / 2;
			if(a[mid] == b) {
				cout << "1\n";
				break;
			}
			else if(a[mid] < b) l = mid + 1;
			else r = mid - 1;
			
			if(r < l) cout << "0\n";
		}
	}
	return 0;
}
