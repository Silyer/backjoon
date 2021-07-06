#include <iostream>
using namespace std;
int b[10] = {0};
bool possi(int num, int m) {//채널을 리모콘 번호를 통해 틀 수 있는가에 대한 bool 함수
	int t = num;
	if(t == 0) {    //예외 : t값이 0이여서 9번줄 while문이 실행되지 않을 때
		for(int i = 0; i < m; i++) if(t == b[i]) return false;
	}
	while(t) {
		int d = t % 10;
		for(int i = 0; i < m; i++) if(d == b[i]) return false;
		t /= 10;
	}
	return true;
}

int mmm(int n, int m) {    //입력받은 채널과 갭이 가장 적은 채널 반환
	int min = -10000000, max = 10000000;
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
	if(n == 0) {        //예외 : 입력 받은 채널이 0인경우
		if(m == 0) return 0;
		for(int i = 0; i < 10; i++) if(i != b[i]) return i;
	}
	if(n - min > max - n) return max;
	else return min;
}

int siz(int a) {        //자릿수 반환
	int len = 0;
	while(a) {
		len++;
		a /= 10;
	}
	return len;
}

int main() {
	int n, m, ch = 100, po_ch = 0, gap = 0, gap_c = 0, si = 0;
	cin >> n;
	cin >> m;
	for(int i = 0; i < m; i++) cin >> b[i];
	sort(b, b + m);
	po_ch = mmm(n, m);
	gap = abs(n - po_ch);//번호로 칠 수 있는 채널과의 갭
	gap_c = abs(ch - n); //현재 틀어져있는 채널(100)과의 갭
	if(po_ch == 0) si = 1;//예외 : 번호로 칠 수 있는 채널이 0일때 siz함수에서 0으로 반환되는 것을 1로 바꿈
	else si = siz(po_ch);
	if(si + gap > gap_c || m == 10) cout << gap_c; //리모콘으로 돌릴수 없거나 현재 채널 선에서 정리 가능할 때 출력
	else cout << si + gap;
	return 0;
}
