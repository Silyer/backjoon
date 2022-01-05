#include <iostream>
#include <queue>
#include <deque>
using namespace std;
int n, k;
bool v[100001];

int bfs(int n, int k) {
	deque<pair<int, int>> q; // 0-1 bfs 알고리즘, 덱을 이용 : 가중치 0은 같은 레벨이므로 덱 앞에, 1은 다른 레벨이므로 덱 뒤에
	q.push_back({ n, 0 });
	v[n] = true;
	while (!q.empty()) {
		int d = q.front().first;  
		int t = q.front().second;
		q.pop_front();
		if (d == k) return t; 
		if (d >= 0 && d * 2 < 100001 && !v[d * 2]) {
			q.push_front({ d * 2, t });
			v[d * 2] = true;
		}
		if (d + 1 >= 0 && d + 1 < 100001 && !v[d + 1]) { 
			q.push_back({ d + 1, t + 1 });
			v[d + 1] = true;
		}
		if (d - 1 >= 0 && d - 1 < 100001 && !v[d - 1]) { 
			q.push_back({ d - 1, t + 1 });
			v[d - 1] = true;
		}
	}
}

int main() {
	cin >> n >> k;
	cout << bfs(n, k);
	return 0;
}
