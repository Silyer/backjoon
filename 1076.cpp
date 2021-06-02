#include <iostream>
#include <string>
using namespace std;
enum Color {black, brown, red, orange, yellow, green, blue, violet, grey, white};
Color con(const string& str) {
	if(str == "black") return black;
	else if (str == "brown") return brown;
	else if (str == "red") return red;
	else if (str == "orange") return orange;
	else if (str == "yellow") return yellow;
	else if (str == "green") return green;
	else if (str == "blue") return blue;
	else if (str == "violet") return violet;
	else if (str == "grey") return grey;
	else if (str == "white") return white;
}
int main() {
	string f, s, t;
	cin >> f;
	cin >> s;
	cin >> t;
	Color one = con(f), two = con(s), thr = con(t);
	if(one == 0 && two == 0) cout << "0";
	else {
		if(one != 0)cout << one;
		cout << two;
		for(int i = 0; i < thr; i++) cout << "0";
	}
	cout << "\n";
	return 0;
}
