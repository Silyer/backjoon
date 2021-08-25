#include <iostream>                       //r배열, vector 모조리 고치기
#include <stack>
#include <vector>
using namespace std;
    
int main() {
	int n, p = 0, p_num = 0, max, p_max = 1000000, r_num = 0;
	scanf("%d", &n);
	vector<int> v(n), num(n);
	char r[200000] = "";
	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
		num[i] = i + 1;
	}
	
	stack<int> s({0});
	bool ok = true;
	
	while(p < n) {
		if(v[p] == n){
			max = v[p];
			p_max = p;
		} 
		if(p > p_max) if(v[p - 1] < v[p]) ok = false;
		if(!ok) break;
		
		if(s.top() < v[p]) {
			for(int i = p_num; i < v[p]; i++) {
				s.push(num[p_num++]);
				r[r_num++] = '+';
			}
		}
		if(s.top() >= v[p]) {
			for(int i = s.top(); i >= v[p]; i--) {
				if(s.top() == 0) break;
				s.pop();
				r[r_num++] = '-';
			}
			p++;
		}
	}
	if(ok) for(int i = 0; i < r.size(); i++) printf("%c\n", r[i]);
	else cout << "NO";
	return 0;
}
