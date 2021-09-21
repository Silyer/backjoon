#include <iostream>
using namespace std;

int main() {
	int a[6][6];
	for(int i = 0; i < 6; i++) {
		for(int j = 0; j < 6; j++) cin >> a[i][j];
	}
	bool ok = false;
	for(int i = 0; i < 6; i++) {
		for(int j = 0; j < 6; j++) {
			if(i < 3) {			//----------------------------------------------------------세로 4개 기둥
				for(int k = 0; k <= 3; k++) {
					if(a[i + k][j] != 0) ok = true;
					if(a[i + k][j] == 0){
						ok = false;	
						break;
					} 
				}
				if(ok) cout << "직선까지 확인" <<'\n';                //debug
				if(ok) {
					if(j > 0 && j < 6) {
						for(int k = 0; k <= 3; k++) {
							if(a[i + k][j - 1] == 0) ok = false;
							else {
								ok = true;
								break;
							}
						}
						for(int k = 0; k <= 3; k++) {
							if(a[i + k][j + 1] == 0) ok = false;
							else {
								ok = true;
								break;
							}
						}
					}
					else ok = false;
				}
				else ok = false;
			}
			
			if(j < 3) {		//-------------------------------------------------------------가로 4개 기둥
				for(int k = 0; k <= 3; k++) {
					if(a[i][j + k] != 0) ok = true;
					if(a[i][j + k] == 0){
						ok = false;	
						break;
					} 
				}
				if(ok) cout << "직선까지 확인" <<'\n';                //debug
				if(ok) {
					if(i > 0 && i < 6) {
						for(int k = 0; k <= 3; k++) {
							if(a[i - 1][j + k] == 0) ok = false;
							else {
								ok = true;
								break;
							}
						}
						for(int k = 0; k <= 3; k++) {
							if(a[i + 1][j + k] == 0) ok = false;
							else {
								ok = true;
								break;
							}
						}
					}
					else ok = false;
				}
				else ok = false;
			}
			
			if(ok) break;
		}
		if(ok) break;
	}
	if(ok) cout << "정육면체";
	else cout << "no";
	return 0;
}
