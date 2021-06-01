#include <iostream>
using namespace std;

int main() {
	int ch, cm, cs, sh, sm, ss, tcs, tss, trs, rh, rm, rs;
	char a;
	cin >> ch >> a >> cm >> a >> cs;
	cin >> sh >> a >> sm >> a >> ss;
	tcs = ch * 3600 + cm * 60 + cs;
	tss = sh * 3600 + sm * 60 + ss;
	if(tcs > tss) trs = 86400 - (tcs - tss);
	else trs = tss - tcs;
	rh = trs / 3600;
	trs %= 3600;
	rm = trs / 60;
	trs %= 60;
	rs = trs;
	printf("%.2d:%.2d:%.2d", rh, rm, rs);
	return 0;
}
