#include <iostream>
using namespace std;
//외적 공식 이용
int main() {
	int x1, x2, x3, y1, y2, y3, m1, m2;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	if ((x1*y2 - x2*y1 + x2*y3 - x3*y2 + x3*y1 - x1*y3) / 2 > 0) cout << "1\n";
	else if ((x1*y2 - x2*y1 + x2*y3 - x3*y2 + x3*y1 - x1*y3) / 2 < 0) cout << "-1\n";
	else cout << "0\n";

	return 0;
}
