#include <iostream>
using namespace std;

int main() {
	int n;
	double re = 0;
	cin >> n;
	double* x = new double[n + 1];
	double* y = new double[n + 1];
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
	for(int i = 0; i < n - 1; i++){
		re += x[i] * y[i + 1];	
		re -= x[i + 1] * y[i];
	} 
	re += (x[n - 1] * y[0] - x[0] * y[n - 1]);
	if(re >= 0) printf("%.1f", re / 2);
	else printf("%.1f", -(re / 2));
	return 0;
}
