#include<iostream>
using namespace std;

bool prev_per(int *a, int n) {
	int i = n - 1;
	while (i > 0 && a[i - 1] <= a[i]) i--; 
	if (i == 0) return false; 
	int j = n - 1;
	while (a[i - 1] <= a[j]) j--;
	swap(a[i - 1], a[j]); 
	j = n - 1; 
	while (i < j) {
		swap(a[i], a[j]);
		i++;
		j--;
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	int a[10000] = {0};
	for (int i = 0; i < n; i++) cin >> a[i];
	if (prev_per(a, n)) {
		for (int i = 0; i < n; i++) cout << a[i] << ' ';
	}
	else cout << -1;

}
