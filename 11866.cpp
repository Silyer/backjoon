#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	queue<int> q;
	
	for(int i = 0; i < n; i++) {
		q.push(i + 1);
	}
	cout << "<";
	while(!q.empty()) {
		for(int i = 0; i < k - 1; i++) {
			int t = q.front();
			q.pop();
			q.push(t);
		}
		cout << q.front();
		q.pop();
		if(!q.empty()) cout << ", ";
	}
	cout << ">";
	return 0;
}
