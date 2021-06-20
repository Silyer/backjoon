#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int n, sum = 0, f[8002] = {0}, max = -1, max_f[500001] = {8001}, t = 0, mod = 0;	//mod 변수 추가(최빈값)
	double avg;
	cin >> n;
	int* m = new int[n + 1];
	
	for(int i = 0; i < n; i++){ 
		cin >> m[i];
		sum += m[i];
		f[m[i] + 4000]++;	//모든 수 (-4000 ~ 4000) 중 특정 수가 있을 시 f[i] = 자연수.
	}
	for(int i = 0; i <= 8000; i++) {	//자연수가 된 f배열에 가장 빈도가 높은 수를 max로 지정.
		if(f[i] > 0) if(max < f[i]) max = f[i];
	}
	for(int i = 0; i <= 8000; i++) {	//max랑 같은 값을 가진 수의 빈도를 크기 순으로 나열.
		if(f[i] == max) max_f[t++] = i;
	}
	if(t <= 1) mod = max_f[0] - 4000;	//최빈값이 하나 이하일 경우.
	else mod = max_f[1] - 4000;		//최빈값이 둘 이상일 경우.
	
	avg = (double)sum / n;
	sort(m, m + n);
	printf("%.0f\n%d\n%d\n%d\n", avg, m[n / 2], mod, m[n - 1] - m[0]);	
	return 0;
}
