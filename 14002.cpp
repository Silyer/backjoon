#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, max = 0, max_i;
	cin >> n;
	vector<int> a(n);                                 //입력받는 수열
	for(int i = 0; i < n; i++) cin >> a[i];
	
	vector<int> d(n);                                 //입력받은 수열의 각 증가하는 수열 최대 길이
	vector<int> b;                                    //최대 증가하는 수열
	for(int i = 0; i < n; i++) {
		d[i] = 1;                                       //각 수열 길이를 1로 초기화
		for(int j = 0; j < n; j++) {
			if(a[j] < a[i] && d[i] < d[j] + 1){           //앞의 수보다 크고 앞의 수열 길이 조건까지 충족되면 
				d[i] = d[j] + 1;                            //앞에 있던 수열까지 증가하여 길이 1 증가
			} 
		}
		if(max < d[i]) {                                //최대 길이와 최대 값 구하기
			max = d[i];
			max_i = i;
		}
	}
	for(int i = max_i; i >= 0; i--) {                 //역탐색, 최대값 인덱스에서 충족하는 인덱스일 시 b수열에 해당 값 추가
		if(d[i] == max) {
			b.push_back(a[i]);
			max--;
		}
	}
	cout << b.size() << '\n';
	for(int i = b.size() - 1; i >= 0; i--) cout << b[i] << ' ';
	return 0;
}
