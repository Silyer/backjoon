#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	string s;
	getline(cin, s);                                    // 띄어쓰기까지 고려, 줄마다 입력 받음
	do{
		stack<int> p;                                     // 괄호가 얼마나 쌓여있는지에 대한 스택
		bool ok = true;                                   // 주어진 조건에 미충족 시 no 출력, 충족 시 yes 출력
		
		for(int i = 0; i < s.length(); i++) {             // 소괄호는 스택에 1 추가, 대괄호는 스택에 2추가.
			if(s[i] == '(') p.push(1);                  
			if(s[i] == '[') p.push(2);
			if(s[i] == ')') {                               // 닫는 괄호일 때 여는 괄호와 짝이 안 맞는 경우 no 출력하게 함
				if(!p.empty()) {
					if(p.top() == 1) p.pop();
					else ok = false;
				}
				else ok = false;
			}
			if(s[i] == ']') {
				if(!p.empty()) {
					if(p.top() == 2) p.pop();
					else ok = false;
				}
				else ok = false;
			}
		}
		if(!p.empty()) ok = false;                        // 스택이 비어있지 않다면 짝이 형성되지 않는 여는 괄호가 있음을 의미, no 출력
		if(ok) cout << "yes" << '\n';
		else cout << "no" << '\n';
		
		s = "";
		getline(cin, s);
	}while(!(s.back() == '.' && s.length() == 1));      // 문장이 "."가 나올 때 까지 
	return 0;
}
