#include <iostream>
#include <queue>
using namespace std;
int n, k;
bool v[100001];

int bfs(int n, int k) {
	queue<pair<int, int>> q;    //first = 위치, second = 시간
	q.push({n, 0});
	v[n] = true;
	while(!q.empty()) {
		int d = q.front().first;  //direction
		int t = q.front().second; //time
		q.pop();
		if(d == k) return t;    //가고자 하는 위치가 k에 다다랐을 경우 그만큼 지난 시간 return 
		if(d + 1 >= 0 && d + 1 < 100001 && !v[d + 1]) {   //1만큼 이동할 경우
			q.push({d + 1, t + 1});
			v[d + 1] = true;
		}
		if(d - 1 >= 0 && d - 1 < 100001 && !v[d - 1]) {   //-1만큼 이동할 경우
			q.push({d - 1, t + 1});
			v[d - 1] = true;
		}
		if(d >= 0 && d * 2 < 100001 && !v[d * 2]) {   // *2만큼 순간이동할 경우
			q.push({d * 2, t + 1});
			v[d * 2] = true;
		}
	}
}

int main() {
	cin >> n >> k;
	cout << bfs(n, k);
	return 0;
}
