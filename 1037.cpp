#include <iostream>
using namespace std;

int main() {
	int n, max = 0, min = 1000000;
	cin >> n;
	int* d = new int [n + 1];
	for(int i = 0; i < n; i++){
		cin >> d[i];	
		if(max < d[i]) max = d[i];
		if(min > d[i]) min = d[i];
	}
	cout << max * min;
	
	return 0;
}
