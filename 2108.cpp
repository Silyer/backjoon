#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int n, sum = 0, f[8002] = {0}, max = 0, max_f[500001] = {0}, t = 0;
	double avg;
	cin >> n;
	int* m = new int[n + 1];
	for(int i = 0; i < n; i++){ 
		cin >> m[i];
		sum += m[i];
		f[m[i] + 4000]++;
	}
	for(int i = 0; i < 8000; i++) {
		if(f[i] > 0) if(max < f[i]) max = f[i];
	}
	for(int i = 0; i < 8000; i++) {
		if(f[i] == max) max_f[t++] = i;
	}
	avg = (double)sum / n;
	sort(m, m + n);
	printf("%.0f\n%d\n%d\n%d\n", avg, m[n / 2], max_f[1] - 4000, m[n - 1] - m[0]);	
	return 0;
}

//반례 : 최빈값이 하나밖에 없을경우 잘못 
