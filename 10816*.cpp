#include <iostream>                   //이분 탐색을 이용하는 문제이나, 무지성 배열로도 풀림. 나중에 수정 요망.
#include <string>
using namespace std;

int main() {
	int n, m;
	scanf("%d", &n);
	int c[20000001] = {0};
	for(int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		c[t + 10000000]++;
	}
	scanf("%d", &m);
	for(int i = 0; i < m; i++) {
		int t;
		scanf("%d", &t);
		printf("%d ",c[t + 10000000]);
	}
	return 0;
}
