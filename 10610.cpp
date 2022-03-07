#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string s;
	int a[100001], sum = 0;
	cin >> s;
	for (int i = 0; i < s.size(); i++) a[i] = s[i] - '0';
	sort(a, a + s.size());
	for (int i = 0; i < s.size(); i++) sum += a[i];
	if (a[0] || sum % 3) cout << -1;
	else for (int i = s.size() - 1; i >= 0; i--) cout << a[i];
	return 0;
}
