#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int a, b, m = 1;
        cin >> a >> b;
        if (b % 4 == 0) b = 4;  // 네 번 마다 끝자리 주기가 같아지므로 4의 나머지의 유무에 따라 판별
        else b %= 4;
        while (b--) m *= a;
        if (m % 10 == 0) cout << 10 << '\n';    // 10번 데이터는 10번 pc가 하므로 10 출력
        else cout << m % 10 << '\n';
    }
}
