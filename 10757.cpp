#include <iostream>
#include <string>
using namespace std;
int main() {
	string a, b;
	int sum[10003] = {0}, j = 1;
	cin >> a >> b;
	if(a.size() == b.size()) {			//두 수의 자릿수 동일
		for(int i = 0; i <= a.size(); i++) {
			int an = a[i] - '0', bn = b[i] - '0';
			sum[j] += an + bn;
			j++;
		}
		for(int i = a.size(); i > 0; i--) { 	//자릿수 10올림
			if(sum[i] >= 10) {
				sum[i - 1] += 1;
				sum[i] %= 10;
			}
		}
		for(int i = 0; i <= a.size(); i++)
			if(sum[0] != 0 || i != 0) cout << sum[i];
	}
	else if(a.size() > b.size()) {			//자릿수가 서로 다름
		for(int i = 0; i < a.size() - b.size(); i++) {
			sum[i] = a[i] - '0';
		}
		for(int i = a.size() - b.size(); i < a.size(); i++) {
			int an = a[i] - '0', bn = b[j - 1] - '0';
			sum[i] += an + bn;
			j++;
		}
		for(int i = a.size() - 1; i > 0; i--) {
			if(sum[i] >= 10) {
				sum[i - 1] += 1;
				sum[i] %= 10;
			}
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
				sum[i] += an + bn;
			j++;
		}
		for(int i = b.size() - 1; i > 0; i--) {
			if(sum[i] >= 10) {
				sum[i - 1] += 1;
				sum[i] %= 10;
			}
		}
		for(int i = 0; i < b.size(); i++)
			if(sum[0] != 0 || i != 0) cout << sum[i];
	}
	return 0;
}
