#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	queue<int> q;
	
	for(int i = 0; i < n; i++){     //n장의 카드를 차례로 번호 넣기
		q.push(i + 1);
	}
	while(q.size() != 1) {          //카드가 1장이 될 때까지 반복
		int t;
		q.pop();                      //1장 빼내고
		t = q.front();                //제일 위에 있는 카드 숫자 기억하고
		q.pop();                      //빼고
		q.push(t);                    //위에 있었던 카드를 아래에 
	}
	cout << q.front();
	return 0;
}
