/*
반례		: (0) 1 -> (1) 3 2 -> (3) 6 7 -> (2) 4 5 순, 이 코드는 무조건 (1) -> (2) -> (3)으로 가기 때문에 오답
7

1 2

1 3

2 4

2 5

3 6

3 7

1 3 2 6 7 4 5

정답 1
출력 0
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, t = 0, top;
vector<int> e[100001];
bool vi[100001];
queue<int> q, o, p;		//p를 pair<int, int>로 선언하여 first엔 부모를 두는 것이 어떨지?
void bfs(int x) {
	vi[x] = true;
	q.push(x);
	p.push(1);		//정점에 무조건 1을 포함하여 시작해야 하기에 넣었음
	while(!q.empty()) {	//while 한 루프 당 p의 역할은 그 만큼의 깊이에 해당하는 수
		x = q.front();
		q.pop();
		for(int i = 0; i < e[x].size(); i++) {
			int y =  e[x][i];
			if(vi[y] == false) {
				vi[y] = true;
				q.push(y);
				p.push(y);
			}
		}
		top = p.front();		//해당 깊이의 최초 수
		while(!p.empty() || !o.empty()) {
			if(o.front() == p.front()) {	//해당 수가 있을 경우 하나씩 나가리, p가 비지 않으면 최초 수 설정
				o.pop();
				p.pop();
				if(p.empty()) break;
				else top = p.front();
			}
			else {		//최초 수에 되돌아 왔다면 순서가 맞지 않는 다는 의미, return
				t = p.front();
				p.pop();
				p.push(t);
				if(p.front() == top) return;
			}
		}
		if(o.empty()) return;
	}
}
int main() {
	cin >> n;
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i = 0; i < n; i++){
		int j;
		cin >> j;
		o.push(j);
	}
	bfs(1);
	if(o.empty()) cout << 1;
	else cout << 0;
	return 0;
}

