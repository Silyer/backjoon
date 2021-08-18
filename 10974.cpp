#include<iostream>
using namespace std;

bool next_per(int *a, int n) {
	int i = n - 1;
	while (i > 0 && a[i - 1] >= a[i]) i -= 1; 
	if (i <= 0) return false; 
	int j = n - 1;
	while (a[j] <= a[i - 1]) j -= 1;
	swap(a[i - 1], a[j]); 
	j = n - 1; 
	while (i < j) {
		swap(a[i], a[j]);
		i += 1;
		j -= 1;
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	int a[10] = {0};
	for (int i = 0; i < n; i++) a[i] = i + 1;
	do{
		for(int i = 0; i < n; i++) cout << a[i] << ' ';
		cout << '\n';
	}
	while(next_per(a, n));
	return 0;
}
