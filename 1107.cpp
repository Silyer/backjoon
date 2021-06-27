//반례가 무엇일까...........
#include <iostream>
using namespace std;
int b[10] = {0};
bool possi(int num, int m) {    //이 채널을 리모콘을 통해 틀 수 있는가?
	int t = num;
	while(t) {
		int d = t % 10;
		for(int i = 0; i < m; i++) if(d == b[i]) return false;
		t /= 10;
	}
	return true;
}

int mmm(int n, int m) {         //채널 기준 갭이 제일 적은 값 반환 
	int min, max;
	for(int i = n; i >= 0; i--) {
		if(possi(i, m)) {
			min = i;
			break;
		}
	}
	for(int i = n; i <= 10000000; i++) {
		if(possi(i, m)) {
			max = i;
			break;
		}
	}
	if(n == 0) {                  //예외 : 채널이 0인경우
		for(int i = 0; i < 10; i++) if(i != b[i]) return i;
	}
	if(n - min > max - n) return max;
	else return min;
}

int siz(int a) {                 //자릿수 반환
	int len = 0;
	while(a) {
		len++;
		a /= 10;
	}
	return len;
}

int main() {
	int n, m, ch = 100, po_ch, gap, gap_c, si;
	cin >> n;
	cin >> m;
	for(int i = 0; i < m; i++) cin >> b[i];
	po_ch = mmm(n, m);
	gap = abs(n - po_ch);         //리모콘으로 가능한 채널과 보고싶은 채널의 갭
	gap_c = abs(ch - n);          //틀어져있는 채널과 보고싶은 채널과의 갭
	if(po_ch == 0) si = 1;        //예외 : 리모콘으로 틀 수 있는 갭이 가장 적은 값이 0일때 사이즈 1로 조정
	else si = siz(po_ch);
	if(si + gap > gap_c || m == 10) cout << gap_c;    //리모콘으로 돌릴수 없거나 현재 채널 선에서 정리 가능할 때 출력
	else cout << si + gap;                            //리모콘을 이용한 출력
	return 0;
}
