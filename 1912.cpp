#include <iostream>
#include <vector>
using namespace std;

int main() { 
	int n;
	cin >> n;
	vector<int> a(n), d(n);                   //a = 입력받은 수열, d = []번째 수로 끝나는 가장 큰 연속합
	for(int i = 0; i < n; i++) cin >> a[i];
	d[0] = a[0];
	int m = d[0];                             //연속합 최댓값은 일단 d[0]부터 시작.
	for(int i = 1; i < n; i++) {
		d[i] = d[i - 1] + a[i];
		if(d[i] < a[i]) d[i] = a[i];            //연속합이 입력받은 수열보다 작을 경우, 그냥 입력받은 수열을 반환
		if(m < d[i]) m = d[i];
	}
	cout << m;
  return 0;
}
