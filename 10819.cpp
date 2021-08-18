#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int n, max = 0;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	do{
		int sum = 0;
		for(int i = 0; i < n - 1; i++) sum += abs(a[i] - a[i + 1]); 
		if(max <= sum) max = sum;
	}
	while(next_permutation(a.begin(), a.end()));
	cout << max;
	return 0;
}
