#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	bool d[1001];
	d[1] = false;
	d[2] = true;
	d[3] = false;
	d[4] = true;
	d[5] = true;
	d[6] = true;
	for (int i = 7; i <= n; i++) {
		d[i] = !d[i - 1] || !d[i - 3] || !d[i - 4];
	}
	if (d[n]) cout << "SK";
	else cout << "CY";
	return 0;
}
