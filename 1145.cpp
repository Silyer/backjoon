#include <iostream>
using namespace std;
int main()
{
    int a[5], re = 0;
    for (int i = 0; i < 5; i++) cin >> a[i];
    while (++re) {
        int c = 0;
        for (int i = 0; i < 5; i++) {
            if (re % a[i] == 0) c++;
        }
        if (c >= 3) {
            cout << re;
            return 0;
        }
    }
}
