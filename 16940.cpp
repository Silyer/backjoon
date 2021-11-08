#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, t = 0, top;
vector<int> e[100001];
bool vi[100001];
queue<int> q, o, p;
void bfs(int x) {
	vi[x] = true;
	q.push(x);
	p.push(1);
	while(!q.empty()) {
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
		top = p.front();
		while(!p.empty() || !o.empty()) {
			if(o.front() == p.front()) {
				o.pop();
				p.pop();
				if(p.empty()) break;
				else top = p.front();
			}
			else {
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
