#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int n, m = 0, k = 0;                          //m, k는 그저 임시 변수.
	cin >> n;
	string s[n], t[n], r[n];                      //t, r 또한 임시 배열.
	for(int i = 0; i < n; i++) {
		cin >> s[i];
	}
	sort(s, s + n);                               //일단 철자 순으로 정렬
	for(int i = 0; i <= 50; i++) {                //문자열의 길이가 짧은 것부터 t배열에 정렬하기
		for(int j = 0; j < n; j++) {
			if(s[j].length() == i) t[m++] = s[j];
		}
	}
	for(int i = 0; i < n; i++) {                  //t배열에서 중복되는 문자열이 있으면 패스, 이후 r배열에 정렬
		bool ok = true;
		for(int j = i + 1; j < n; j++) {
			if(t[i] == t[j]) ok = false;
		}
		if(ok) r[k++] = t[i];
	}
	for(int i = 0; i < k; i++) {                  //최종적으로 정렬된 r배열 출력
		cout << r[i] << '\n';
	}
	return 0;
}
