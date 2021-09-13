#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, r = 0;
	cin >> n;
	while(n--) {
		string s;
		cin >> s;
		int a[101] = {0}, no[101] = {0};                      //a = 문자열을 int로 치환한 배열, no = 중복이 된 문자열은 1, 외 0
		bool ok = true;                                       //그룹문자가 아닐 시 false 반환
		for(int i = 0; i < s.size(); i++) a[i] = s[i] - 'a';
		for(int i = 1; i < s.size(); i++) {
			if(a[i] != a[i - 1]) no[i - 1] = 1;                 //연이어 붙어있는 철자를 제외한 중복되는 문자열은 1
			for(int j = 0; j < i; j++) {
				if(a[i] == a[j] && no[j] == 1){                   
					ok = false;
					break;
				} 
			}
		}
		if(ok) r++;
	}
	cout << r;
	return 0;
}
