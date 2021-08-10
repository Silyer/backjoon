#include <iostream>
#include <string>
using namespace std;

int main() {
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) {
		string s;
		int n = 0;                                //괄호 (가 몇 개 들어갔는지?
		bool ok = true;                           //예외에 적용되지 않는지?
		cin >> s;
		for(int j = 0; j < s.length(); j++) {
			if(s[j] == '(') n++;                    //(괄호가 들어가면 n증가
			else if(s[0] == ')'){                   //예외 : 처음부터 )가 들어갔을 때
				cout << "NO" << '\n';
				ok = false;
				break;
			}
			else if(s[j] == ')' && j != 0) n--;     //)괄호가 들어가면 n 감소
			
			if(n < 0){                              //예외 : )괄호가 (괄호보다 많아질 때
				cout << "NO" <<'\n';
				ok = false;
				break;
			} 
		}
		if(n == 0 && ok == true) cout << "YES" << '\n';
		else if(n != 0 && ok == true) cout << "NO" << '\n';
	}
	return 0;
}
