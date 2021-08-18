#include<iostream>
using namespace std;

bool next_per(int *a, int n) {
	int i = n - 1;
	while (i > 0 && a[i - 1] >= a[i]) i -= 1;         //내림차순이 어디까지 가는지 i로 확인
	if (i <= 0) return false;                         //마지막 수열이면 false 반환
  
	int j = n - 1;  
	while (a[j] <= a[i - 1]) j -= 1;                  //내림차순 앞의 숫자 다음으로 내림차순에서 진행되는 숫자 중 큰 것을 선택
  
	swap(a[i - 1], a[j]);                             //선택한 숫자 j랑 스왑
  
	j = n - 1;                                        //마지막 수열
	while (i < j) {                                   //내림차순을 오름차순으로 바꿈 (내림차순으로 진행된 수열 -> 오름차순으로 진행 수열시작
		swap(a[i], a[j]);
		i += 1;
		j -= 1;
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	int a[10000] = {0};
	for (int i = 0; i < n; i++) cin >> a[i];
	if (next_per(a, n)) {                                   //위의 함수가 true이면 다음 수열 반환, 조건과 안 맞을 시 -1 
		for (int i = 0; i < n; i++) cout << a[i] << ' ';
	}
	else cout << -1;

}
