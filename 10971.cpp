#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int n, min = 100000000;
	cin >> n;
	vector<vector<int>> t(n, vector<int>(n, 0));          //순회하는 비용 
	vector<int> a(n);                                     //순열로 표현
	for (int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) cin >> t[i][j];
		a[i] = i;
	}
	
	do{
		bool ok = true;                                     //이 도시를 지나는 데 i -> i를 안지나는가?
		int sum = 0;
		for(int i = 0; i < n - 1; i++) {
			if(t[a[i]][a[i + 1]] == 0) ok = false;            //i -> i를 지나면 false
			else sum += t[a[i]][a[i + 1]];                    //1 2 3 4순열일경우 1->2, 2->3, 3->4 비용 합산
		}
		if(ok && t[a[n - 1]][a[0]] != 0) {                  //i -> i로 안지나는 조건일 때 4->1로 순회하는 비용까지 더함
			sum += t[a[n - 1]][a[0]];
			if(min > sum)min = sum;
		}

	}
	while(next_permutation(a.begin(), a.end()));
	cout << min;
	return 0;
}
