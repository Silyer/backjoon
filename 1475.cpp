#include <iostream>
#include <string>
using namespace std;

int main()
{
    string n;
    int m = -1;
    int a[10] = { 0, }, b[8] = {0, 1, 2, 3, 4, 5, 7, 8}; // a = 카운팅 배열, b = 6, 9를 제외한 배열
    cin >> n;
    for (int i = 0; i < n.size(); i++) a[n[i] - '0']++; // 0이 첫자리 수일 예외를 고려, string으로 받아 배열에 카운트
    for (int i = 0; i < 10; i++) if (m < a[i]) m = a[i]; // 최댓값 찾기
    for (int i = 0; i < 8; i++) {   //6, 9를 제외한 최댓값 먼저 찾기 : 1199같은 반례 고려
        if (a[b[i]] == m) {
            cout << m;
            return 0;
        }
    }
    if (a[6] == m || a[9] == m) { //6, 9중 최댓값이 있을 때 
        m = (a[6] + a[9]) / 2;
        if (((a[6] + a[9]) % 2) > 0) m++;
    }
    cout << m;
}
