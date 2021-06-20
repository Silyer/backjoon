#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, d = 666, m[10001] = {0}, i = 0;
	cin >> n;
	while(i != 10000) {
		int si = 0;
		string s = to_string(d);
		for(int j = 0; j < s.size() - 2; j++) {
			for(int k = j; k < j + 3; k++) {
				if(s[k] == '6') si++;
			}
			if(si >= 3) {
				m[i++] = d;
				break;
			}
			else si = 0;
		}
		d++;
	}
	cout << m[n - 1];
	return 0;
}
//이것보다도 더 단순하게 하는 방법 : 그냥 1000으로 나눈 나머지가 666이 되는지 bool..
