#include <iostream> // 트리 부모 찾기는 bfs 알고리즘을 통해 풀었음.
#include <vector>
#include <queue>
using namespace std;

vector<int> a[100001];  // 트리를 인접 리스트 형태로 표현
queue<int> q;
int parent[100001];   // 해당 정점의 부모를 찾는 배열
bool v[100001];   // 방문 여부
int dep[100001];  // 깊이 배열

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {   // 정점 연결
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	dep[1] = 0;   // 루트이자 1을 0층으로 지정
	v[1] = true;  // 루트이자 1을 방문했다고 하자

	q.push(1);
	parent[1] = 0;  // 1의 부모는 없는 것 - 0으로 표현, 사실상 출력하는 데 있어서 없어도 되는 구문.
	while (!q.empty()) {    // bfs 알고리즘으로 풀기
		int x = q.front();
		q.pop();
		for (int i : a[x]) {
			if (!v[i]) {  // 방문 안한 곳이면 부모보다 1층 더 낮게, 부모 기록, bfs 구현 등
				dep[i] = dep[x] + 1;
				v[i] = true;
				parent[i] = x;
				q.push(i);
			}
		}
	}
	for (int i = 2; i <= n; i++) cout << parent[i] << '\n';   // 2번 노드부터 순서대로 출력하므로
	return 0;
}

