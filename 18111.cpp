#include <iostream>
#include <vector>
using namespace std;
//높이 낮은게 빈도 적다 (블록 써서 적은 곳 높이기) 쌓기 1초
// > 높이 높은게 빈도 적다 (적은곳 파기) 파기 2초
// > (빈도 적은 곳을 높은 곳에 맞춰 쌓기) 쌓기 1초
// > 높이 낮은게 빈도 적으나 블록이 없다(빈도 많은 곳을 낮은곳에 맞춰 파기)
int main() {
	int n, m, b;
	cin >> n >> m >> b;
	vector<vector<int>> h(n, vector<int>(m, 0));    
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) cin >> h[i][j];
	}
	
	int p = 0, r = 100000000, r_h = 0;            //p = 현재 높이, r = 최소 시간, r_h = 최소 시간 & 가장 높은 높이
	
	for(p; p <= 256; p++){
		int ti = 0, t = b;                          //ti = 현재 p값에 나오는 시간, t = 임시 b 변수
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(h[i][j] < p){                        //(i, j)높이가 p보다 낮으면 블럭을 소비하고 개당 1초의 시간 소모하며 높이 맞추기
					ti += (p - h[i][j]);
					t -= p - h[i][j];
				}
				else if (h[i][j] > p) {                 //(i, j)높이가 p보다 높으면 블럭을 부숴 얻고 개당 2초의 시간 소모하며 높이 맞추기
					ti += 2 * (h[i][j] - p);
					t += h[i][j] - p;
				}
			}
		}
		if(t >= 0 && r >= ti){                      //최종적으로 블록이 없어 만들지 못하는 높이가 아니거나 현재 시간이 최솟값인 경우
			r = ti;	                                  //결과값 
			r_h = p;
		}
	}
	cout << r << ' ' << r_h;
	return 0;
}
