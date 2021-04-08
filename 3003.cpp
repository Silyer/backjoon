#include <iostream>
using namespace std;

int main() {
	int a[6] = {0};
	for(int i = 0; i < 6; i++){ 
		cin >> a[i];
		if(i == 0) cout << 1 - a[i] << " ";
		else if(i == 1) cout << 1 - a[i] << " ";
		else if(i == 2) cout << 2 - a[i] << " ";
		else if(i == 3) cout << 2 - a[i] << " ";
		else if(i == 4) cout << 2 - a[i] << " ";
		else if(i == 5) cout << 8 - a[i] << " ";
	}
	
	return 0;
}
