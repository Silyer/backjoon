#include <iostream>
#include <stack>
using namespace std;

int main() {
	int k;
	unsigned long long c = 0;
	cin >> k;
	stack <int> s;
	while(k--) {
		int n;
		cin >> n;
		if(n != 0) s.push(n);
		else s.pop();
	}
	while(!s.empty()){ 
		c += s.top();
		s.pop();
	}
	cout << c;
	return 0;
}
