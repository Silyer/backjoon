#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int k;
	cin >> k;
	while(k != 0) {
		vector<int> s(k);                                         //로또번호가 오름차순으로 적혀있는 벡터
		vector<int> c(k, 0);                                      //6개를 선택하는 벡터, 1과 0으로 구성
		for(int i = 6; i < k; i++) c[i] = 1;                      //상위 6개를 0으로 지정, 나머지는 1로 구성
		for(int i = 0; i < k; i++) cin >> s[i];
		do {                                                      //6개의 0과 1로 구성된 수열을 이용해 선택된 0 벡터의 로또번호 
			for(int i = 0; i < k; i++) {
				if(!c[i]) cout << s[i] << ' ';
			}
			cout << '\n';
		} while(next_permutation(c.begin(), c.end()));
		cin >> k;
		cout << '\n';
	}
	
	return 0;
}
