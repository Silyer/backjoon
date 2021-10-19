#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
  cin.tie(0);
	long long n, re = 0;
	cin >> n;
	vector<int> a(n + 1, 0);
	stack<int> s({0}), m({0});    //s = 탑의 ?번째, m = ?번째 탑의 높이
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 1; i <= n; i++) {
		if(a[i] <= m.top()) {            
			cout << s.top() << ' ';
		}
		else {
			while(!m.empty()) {
				m.pop();
				s.pop();
				if(m.empty()) {
					cout << 0 << ' ';
					break;
				}
				if(a[i] <= m.top()){
					cout << s.top() << ' ';;
					break;
				} 
			}
		}
		m.push(a[i]);
		s.push(i);
	}
	return 0;
}

