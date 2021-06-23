#include <iostream>
using namespace std;

int main() {
	 int e, s, m, i = 0;
	 cin >> e >> s >> m;
	 int ee = 0, ss = 0, mm = 0;
	 while(i<=7980) {
	 	if(e == ee && s == ss && m == mm) cout << i;
	 	ee++;
	 	ss++;
	 	mm++;
	 	if(ee > 15) ee = 1;
	 	if(ss > 28) ss = 1;
	 	if(mm > 19) mm = 1;
	 	++i;
	 }
	return 0;
}
