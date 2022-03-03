#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	bool d[1001];
	d[1] = true;
	d[2] = false;
	d[3] = true;
	d[4] = true;
	for (int i = 5; i <= 1000; i++) {
		d[i] = !d[i - 1] || !d[i - 3] || !d[i - 4];
	}
	if (d[n]) cout << "SK";
	else cout << "CY";
	return 0;
}
/*	
d[1] = sk, d[2] = cy, d[3] = sk,  d[4] = sk, 
*/	
