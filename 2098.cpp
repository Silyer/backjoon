#include <iostream>
using namespace std;
int n;
int w[16][16];
int d[1 << 16][16] = {0};
int solve(int vi, int now) {    //vi = 이미 방문한 도시, now = 이번에 갈 도시
	vi |= (1 << now);     //이번에 갈 도시를 방문한 도시에 추가
	
	if(vi == (1 << n) - 1) {      //도시를 모두 방문했다면 (now에서 시작 도시인 0에 갈 때) 비용 반환 / 불가능 시 99999999
		if(w[now][0] > 0) return w[now][0];
		return 99999999;
	}
	
	if(d[vi][now] > 0) return d[vi][now];
	d[vi][now] = 99999999;
	
	for(int i = 0; i < n; i++) {    //이동할 도시가 같지 않고, 비용이 0보다 크며, 아직 방문하지 않은 도시인 경우
		if(i != now && w[now][i] > 0 && (vi & (1 << i)) == 0) {
			int t = solve(vi, i) + w[now][i];     // t에 재귀한 값 + 경로 비용 추가
			if(d[vi][now] > t) d[vi][now] = t;    // 최소 비용 갱신
		}
	}
	return d[vi][now];
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) cin >> w[i][j];
	}
	int re = solve(0, 0);
	if(re != 99999999) cout << re;
	return 0;
}

