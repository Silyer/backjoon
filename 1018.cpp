#include <iostream>
using namespace std;

int main() {
	int n, m, minB = 3000, minW = 3000, c = 0;                //고쳐야 하는 타일 수 최대 3000개라 가정 (실2500 최대)_
	cin >> n >> m;
	char bo[51][51] = {0};                                    //처음에 입력 받는 타일
	int chB[51][51] = {0};                                    //맨 왼쪽 위의 타일이 B일 때 몇 개의 타일을 고쳐야하는가?
	int chW[51][51] = {0};                                    // ''  W일 때 몇 개의 타일을 고쳐야하는가? 
	for(int i = 0; i < n; i++) {                              //보드 입력 받음
		for(int j = 0; j < m; j++) {
			cin >> bo[i][j];
		}
	}
	
	for(int i = 0; i < n; i++) {                              //맨 왼쪽 위의 타일이 B일 때 고쳐야 하는 타일을 좌표마다 0과 1로 표현
		for(int j = 0; j < m; j++) {
			if(i % 2 == 0) {
				if(j % 2 == 0 && bo[i][j] != 'B') chB[i][j]++;
				if(j % 2 != 0 && bo[i][j] != 'W') chB[i][j]++;
			}
			else { 
				if(j % 2 == 0 && bo[i][j] != 'W') chB[i][j]++;
				if(j % 2 != 0 && bo[i][j] != 'B') chB[i][j]++;
			}
		}
	}
	
	for(int i = 0; i < n; i++) {                              //맨 왼쪽 위의 타일이 W일 때 고쳐야 하는 타일을 좌표마다 0과 1로 표현
		for(int j = 0; j < m; j++) {
			if(i % 2 == 0) {
				if(j % 2 == 0 && bo[i][j] != 'W') chW[i][j]++;
				if(j % 2 != 0 && bo[i][j] != 'B') chW[i][j]++;
			}
			else { 
				if(j % 2 == 0 && bo[i][j] != 'B') chW[i][j]++;
				if(j % 2 != 0 && bo[i][j] != 'W') chW[i][j]++;
			}
		}
	}
  
	for(int i = 0; i <= n - 8; i++) {                         //8 * 8로 끊어서 고쳐야 하는 타일 최솟값 구하기(맨왼위 타일 B)
		for(int j = 0; j <= m - 8; j++) {
			int t = 0;
			for(int a = i; a < i + 8; a++) {
				for(int b = j; b < j + 8; b++) {
					t += chB[a][b];
				}
			}
			if(minB > t) minB = t;
		}
	}
	
	for(int i = 0; i <= n - 8; i++) {                         //8 * 8로 끊어서 고쳐야 하는 타일 최솟값 구하기(맨왼위 타일 W)
		for(int j = 0; j <= m - 8; j++) {
			int t = 0;
			for(int a = i; a < i + 8; a++) {
				for(int b = j; b < j + 8; b++) {
					t += chW[a][b];
				}
			}
			if(minW > t) minW = t;
		}
	}
	if(minB <= minW) cout << minB;                            //최종 최솟값 
	else cout << minW;
	return 0;
}
