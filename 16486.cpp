#include <iostream>
using namespace std;

int main() {
	double pi = 3.141592;
	int d1, d2;
	cin >> d1 >> d2;
	printf("%.6f", d1 * 2 + d2 * 2 * pi);
	return 0;
}
