#include <iostream>
#include <string>
using namespace std;
//9999 + 99
//99 + 9999 반례 이해
int main() {
	string a, b;
	int sum[10003] = {0}, j = 1;
	cin >> a >> b;
	if(a.size() == b.size()) {
		for(int i = 0; i <= a.size(); i++) {
			int an = a[i] - '0', bn = b[i] - '0';
			if(an + bn >= 10){
				sum[j - 1] += 1;
				sum[j] += (an + bn) % 10;
			} 
			else sum[j] += an + bn;
			j++;
		}
		for(int i = 0; i <= a.size(); i++)
			if(sum[0] != 0 || i != 0) cout << sum[i];
	}
	else if(a.size() > b.size()) {
		for(int i = 0; i < a.size() - b.size(); i++) {
			sum[i] = a[i] - '0';
		}
		for(int i = a.size() - b.size(); i < a.size(); i++) {
			int an = a[i] - '0', bn = b[j - 1] - '0';
			if(an + bn >= 10){
				sum[i - 1] += 1;
				sum[i] += (an + bn) % 10;
			} 
			else {
				sum[i] += an + bn;
			}
			j++;
		}
		for(int i = 0; i < a.size(); i++)
			if(sum[0] != 0 || i != 0) cout << sum[i];
	}
	else{
		for(int i = 0; i < b.size() - a.size(); i++) {
			sum[i] = b[i] - '0';
		}
		for(int i = b.size() - a.size(); i < b.size(); i++) {
			int an = a[j - 1] - '0', bn = b[i] - '0';
			if(an + bn >= 10){
				sum[i - 1] += 1;
				sum[i] += (an + bn) % 10;
			} 
			else {
				sum[i] += an + bn;
			}
			j++;
		}
		for(int i = 0; i < b.size(); i++)
			if(sum[0] != 0 || i != 0) cout << sum[i];
	}
	return 0;
}
