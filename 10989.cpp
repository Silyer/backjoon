#include <iostream>
using namespace std;

int main() {
	int n, a, c[10001] = {0}; //카운팅 정렬, count배열 (수 범위 0~10000) 생성
	scanf("%d", &n);
	for(int i = 0; i < n; i++){ 
		scanf("%d", &a);
		c[a - 1]++;             //입력된 수 개수를 count배열에 저장 (빈도)
	} 
	
	for(int i = 0; i < 10000; i++){
		for(int j = 0; j < c[i]; j++) printf("%d\n", i + 1);
	}
	return 0;
}
