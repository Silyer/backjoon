#include <iostream>                    
#include <stack>
#include <vector>
using namespace std;
    
int main() {
	int n, p = 0, d_num = 0, p_num = 0, r_num = 0;			//p = 현재 수, d_num = 삭제되는 수 n번째
	scanf("%d", &n);						//p_num = 현재 수의 n번째, r_num = 결과의 n번째
	vector<int> v(n), num(n);					//v = 입력받은 수열, num = 스택에 넣을 수 벡터
	int del[200000] = {0};						//스택에서 삭제된 수 배열
	char r[300000] = "";						// +, - 로 이루어진 결과 배열
	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
		num[i] = i + 1;
	}
	
	stack<int> s({0});						//스택 수열, s.top 오류방지 목적으로 1층에 0으로 초기화
	bool ok = true;							//스택으로 수열을 만들수 있는가?
	
	while(p < n) {
		for(int i = 0; i < d_num; i++) {
			if(del[i] == v[p]) ok = false;			//삭제된 수열과 입력 받은 수열이 겹치면 No 출력
		}
		if(!ok) break;
		
		if(s.top() < v[p]) {					// +를 표기하기 위한 조건문
			for(int i = p_num; i < v[p]; i++) {
				s.push(num[p_num++]);
				r[r_num++] = '+';
			}
		}
		if(s.top() >= v[p]) {					// -를 표기하기 위한 조건문
			for(int i = s.top(); i >= v[p]; i--) {
				if(s.top() == 0) break;			//예외 : 뺄려는 수열이 스택 밑바닥일 때
				del[d_num++] = s.top();			//이 때 삭제되는 수는 del배열에 저장
				s.pop();
				r[r_num++] = '-';
			}
			p++;
		}
	}
	if(ok) for(int i = 0; i < r_num; i++) printf("%c\n", r[i]);
	else printf("NO");
	return 0;
}
