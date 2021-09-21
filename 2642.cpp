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
			if(i < 3) {			//-----------------------------세로 4개 기둥
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
				if(ok) break;
			}
			
			if(j < 3) {		//---------------------------------가로 4개 기둥
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
				if(ok) break;
			}
			if(i < 4) {		//---------------------------------세로 3개 기둥
				for(int k = 0; k <= 2; k++) {
					if(a[i + k][j] != 0) ok = true;
					if(a[i + k][j] == 0){
						ok = false;	
						break;
					} 
				}
				if(ok) cout << "직선까지 확인" <<'\n';                //debug
				if(ok) {
					if(j > 0 && j < 6) {
						if(i > 0 && a[i - 1][j - 1] != 0 && a[i][j - 1] != 0) {
							for(int k = 0; k <= 2; k++) {
								if(a[i + k][j - 1] == 0) ok = false;
								else {
									ok = true;
									break;
								}
							}
						}
						else if(i < 3 && a[i + 2][j - 1] != 0 && a[i + 3][j - 1] != 0) {
							for(int k = 0; k <= 2; k++) {
								if(a[i + k][j - 1] == 0) ok = false;
								else {
									ok = true;
									break;
								}
							}
						}
						else if(i > 0 && a[i - 1][j + 1] != 0 && a[i][j + 1] != 0) {
							for(int k = 0; k <= 2; k++) {
								if(a[i + k][j + 1] == 0) ok = false;
								else {
									ok = true;
									break;
								}
							}
						}
						else if(i < 3 && a[i + 2][j + 1] != 0 && a[i + 3][j + 1] != 0) {
							for(int k = 0; k <= 2; k++) {
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
				else ok = false;
				if(ok) break;
			}
			
			if(j < 4) {		//---------------------------------가로 3개 기둥
				for(int k = 0; k <= 2; k++) {
					if(a[i][j + k] != 0) ok = true;
					if(a[i][j + k] == 0){
						ok = false;	
						break;
					} 
				}
				if(ok) cout << "직선까지 확인" <<'\n';                //debug
				if(ok) {
					if(i > 0 && i < 6) {
						if(j > 0 && a[i - 1][j - 1] != 0 && a[i - 1][j] != 0) {
							for(int k = 0; k <= 2; k++) {
								if(a[i - 1][j + k] == 0) ok = false;
								else {
									ok = true;
									break;
								}
							}
						}
						else if(j < 3 && a[i - 1][j + 2] != 0 && a[i - 1][j + 3] != 0) {
							for(int k = 0; k <= 2; k++) {
								if(a[i - 1][j + k] == 0) ok = false;
								else {
									ok = true;
									break;
								}
							}
						}
						else if(j > 0 && a[i + 1][j - 1] != 0 && a[i + 1][j] != 0) {
							for(int k = 0; k <= 2; k++) {
								if(a[i + 1][j + k] == 0) ok = false;
								else {
									ok = true;
									break;
								}
							}
						}
						else if(j < 3 && a[i + 1][j + 2] != 0 && a[i + 1][j + 3] != 0) {
							for(int k = 0; k <= 2; k++) {
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
				else ok = false;
				if(ok) break;
			}
			
		}
		if(ok) break;
	}
	if(ok) cout << "정육면체";
	else cout << "no";
	return 0;
}
