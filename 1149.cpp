#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, re = 99999999;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(3, 0));
	vector<vector<int>> mm(n, vector<int>(3, 0));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 3; j++) {
			cin >> a[i][j];
			mm[i][j] = a[i][j];
		}
		sort(mm[i].begin(), mm[i].end());
	}
	for(int i = 0; i < n; i++) {
		int min = mm[i][0];
		int min_i = min_element(a[i].begin(), a[i].end()) - a[i].begin();
		int m = min;
		cout << m << ' ';
		for(int j = 0; j < n; j++) {
			int t_i = min_element(a[j].begin(), a[j].end()) - a[j].begin();
			if(j == i) continue;
			else if(j - i == 1 || j - i == -1){
				if(min_i != t_i){
					cout << mm[j][0] << ' ';
					m += mm[j][0];
					
				} 
				else{
					cout << mm[j][1] << ' ';
					m += mm[j][1];
					
				} 
			}
			else if(j - i < -1){
				int min_j = min_element(a[j - 1].begin(), a[j - 1].end()) - a[j - 1].begin();
				if(t_i == )
				cout << mm[j][0] << ' ';
				m += mm[j][0];
			}
			else if(j - i > 1){
				if(mm[j][0])
			}
		}
		cout << "  |  ";
		if(re > m) re = m;
	}
	cout << re;
	return 0;
}
/*
a 26 40 83		d 0 26		a 40 50 83	d 0 40	1 50  2 83	
  49 60 57		  3 57		  60 49 57	  1 49	2 57  1 49
  13 89 99		  0 13		  89 19 99	  0 89	1 19  0 89
d[i][0] = min(d[i - 1][1], d[i - 1][2]) + a[i][0]
d[i][1] = min(d[i - 1][0], d[i - 1][2]) + a[i][1]
d[i][2] = min(d[i - 1][0], d[i - 1][1]) + a[i][2]
*/
