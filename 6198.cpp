#include <iostream>
#include <stack>
#include <vector>
#define MAX 1000000001
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
  cin.tie(0);
	long long n, re = 0;
	cin >> n;
	vector<int> a(n + 1, 0);
	stack<int> s({n + 1}), m({MAX});          //맨 오른쪽 빌딩 관리인은 다른 옥상을 못 보므로 임의의 범위를 넘는 빌딩 하나 두어 못본다고 가정
	for(int i = 1; i <= n; i++) cin >> a[i];  //stack s = ?번째 빌딩 스택, m = ?번째 빌딩의 높이 스택
	
	for(int i = n; i >= 1; i--) {
		if(a[i] <= m.top()) {                   //i번째 빌딩이 ?번째 빌딩보다 낮을 경우 ?번째 전 빌딩부터 i번째 빌딩보다 낮았던 빌딩을 결과값에 추가
			re += s.top() - i - 1;
		}
		else {
			while(!m.empty()) {
				m.pop();
				s.pop();
				if(a[i] <= m.top()){
					re += s.top() - i - 1;
					break;
				} 
			}
		}
		m.push(a[i]);
		s.push(i);
	}
	cout << re;
	return 0;
}
/*test case
10 3 7 4 12 2

2 - m : MAX(7), push 2(6) | n = 6 -> 0 
12 - m : 2(6), pop, MAX(7), push 12(5) | n = 5 -> 1
4 - m : 12(5), push 4(4) | n = 4 -> 1
7 - m : 4(4), pop, 12(5), push 7(3) | n = 3 -> 2
3 - m : 7(3), push 3(2) | n = 2 -> 2
10 - m : 3(2), pop, 7(3), pop, 12(5), push 10(1) | n = 1 -> 5

*/
