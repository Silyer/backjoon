#include <iostream>
using namespace std;

int main()
{
	long long n;
	cin >> n;
	bool d[7];
	d[1] = true;
	d[2] = false;
	d[3] = true;
	d[4] = true;
	d[5] = true;
	d[6] = true;
	d[0] = false;
	
	if (d[n % 7]) cout << "SK";
	else cout << "CY";
	return 0;
}
