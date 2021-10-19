#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);              //이걸 넣으니 500ms나 줄어들었네 홀리;;
  cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n, 0);
	stack<int> s, m({0});                      //s = 오큰수 스택, m = 뒤에서 부터 축적되는 큰 값 스택
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = n - 1; i >= 0; i--) {
		if(a[i] < m.top()) {                     //뒤에서 부터 오큰수 충족 시 s스택에 답 축적
			s.push(m.top());
		} 
		else {                                   //미충족 시 m스택에서 i번째 값이 오큰수가 충족될 수 있도록 m이 빌 때까지 무한 pop
			while(!m.empty()) { 
				m.pop();
				if(m.empty()) {                      //m스택이 비어도 미충족(오큰수가 없다)일 시 -1 축적
					s.push(-1);
					break;
				}
				if(a[i] < m.top()){
					s.push(m.top());
					break;
				} 
			}
		}
		m.push(a[i]);
	}
	while(!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
	return 0;
}

/*test case
7
 9 5 6 2 4 7  8
 
-1 6 7 4 7 8 -1

8 - m : 0, pop, empty, push 8-> -1
7 - m : 8, push 7 -> 8
4 - m : 7, push 4 -> 7
2 - m : 4, push 2 -> 4
6 - m : 2, pop, 4, pop, 7, push 6 -> 7
5 - m : 6, push 5 -> 6
9 - m : 5, pop, 6, pop, 8, pop, empty, push 9 -> 1
*/

