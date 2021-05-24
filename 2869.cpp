#include <iostream>
using namespace std;

int main() {
	int a, b, v, re;
	cin >> a >> b >> v;
	re = (v - a) / (a - b) + 1;
	if((v - a) % (a - b) > 0) re++;
	cout << re;
	return 0;
}
