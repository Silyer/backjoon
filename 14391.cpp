#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, m, re = 0;
	cin >> n >> m;
	int a[4][4];
	string s;
	
	for(int i = 0; i < n; i++){
		cin >> s;
		for(int j = 0; j < m; j++) {
			a[i][j] = s[j] - '0';
		}
	}  
                                                    
	for (int s = 0; s < (1 << (n * m)); s++) {        //n * m 종이서 가로 = 0, 세로 = 1로 2 ^ (n * m)가지의 경우를 나타냄
		int sum = 0;
    
		for(int i = 0; i < n; i++) {                    //가로
			int hor = 0;
      
			for(int j = 0; j < m; j++) {
				int k = i * m + j;                          //k = 종이에 있는 k번째 조각
        
				if((s & (1 << k)) == 0) {                   //s에서 나온 수가 0이고, 연속되면 그만큼 수가 형성됨
					hor = hor * 10 + a[i][j];
        }     
        
				else {                                      //s가 0이 아닐 때, 연속이 끊기고 hor 변수는 초기화, sum에 추가
					sum += hor;
					hor = 0;
				}
			}
      
			sum += hor;                                   //마지막으로 계산한 hor 까지도 추가
		}
    
		for(int j = 0; j < m; j++) {                    //세로.  가로에서 하는 방식이랑 유사
			int ver = 0;
      
			for(int i = 0; i < n; i++) {
				int k = i * m + j;
        
				if((s & (1 << k)) != 0) {
					ver = ver * 10 + a[i][j];	
				} 
        
				else {
					sum += ver;
					ver = 0;
				}
			}
      
			sum += ver;
		}
    
		if(re < sum) re = sum;                          //최댓값 
	}
	cout << re;
	return 0;
}
