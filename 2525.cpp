#include <iostream>
using namespace std;

int main() {
	int a, b, c, t;
	cin >> a >> b >> c;
	t = a * 60 + b + c;
	if(t >= 1440) t %= 1440;
	cout << t / 60 << " " << t % 60;
	return 0;
}
