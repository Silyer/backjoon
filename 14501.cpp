#include <iostream>
#include <vector>
using namespace std;

int n, re = 0;
int t[20], p[20];

void leave(int day, int sum) {            //day = 시간, sum = 시간에 따라 번 금액
	if(day == n + 1){                       //n + 1일에 맞춰 퇴사 할 경우 re 값 반환
		if(re < sum) re = sum;
		return;
	} 
	if(day > n + 1) return;                 //시간에 맞춰 퇴사를 하지 못하면 x
	leave(day + 1, sum);                    //특정 날에 상담을 하지 않을 때
	leave(day + t[day], sum + p[day]);      //특정 날에 상담을 할 때
}

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> t[i] >> p[i];
	leave(1, 0);                            //1일부터, 0원을 가지고 
	cout << re;
	return 0;
}
