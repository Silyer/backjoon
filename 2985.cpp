#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if(c == a + b) printf("%d+%d=%d", a, b, c);
	else if (c == a - b) printf("%d-%d=%d", a, b, c);
	else if (c == a * b) printf("%d*%d=%d", a, b, c);
	else if (c == a / b) printf("%d/%d=%d", a, b, c);
	else if (a == b + c) printf("%d=%d+%d", a, b, c);
	else if (a == b - c) printf("%d=%d-%d", a, b, c);
	else if (a == b * c) printf("%d=%d*%d", a, b, c);
	else if (a == b / c) printf("%d=%d/%d", a, b, c);
	return 0;
}
