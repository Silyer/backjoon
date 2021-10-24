#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int n, re = 0;  //re = 총 단지 수
int a[26][26];
int d[400] = {0};   //특정 한 단지 내에 있는 건물 수 
bool v[26][26];
int dx[] = {1, -1, 0, 0}; //상하좌우
int dy[] = {0, 0, 1, -1};

void dfs(int x, int y, int t) {   //t = t번째 단지
	d[t]++;       
	v[x][y] = true;
	for(int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(a[nx][ny] == 1 && !v[nx][ny]) dfs(nx, ny, t);    //다음에 방문할 곳에 집이 있고, 방문 안 했을 때 탐색
	}
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		string s;   //입력이 한 줄마다 붙어있기에 string으로 입력 받고 하나씩 떼어 배열에 넣음
		cin >> s;
		for(int j = 0; j < n; j++) {
			a[i][j] = s[j] - '0';
		}
	}
  
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(a[i][j] == 1 && !v[i][j]) {    //새로운 단지를 발견했을 경우 그 단지를 탐색, 총 단지 수 ++
				dfs(i, j, re);
				re++;
			}
		}
	}
  
	sort(d, d + re);      //오름차순으로 정렬하여 출력해야하기에 정렬함
	cout << re << '\n';
	for(int i = 0; i < re; i++) {
		cout << d[i] << '\n';
	}
	return 0;
}
