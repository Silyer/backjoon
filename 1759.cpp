#include <iostream>                                           //조합을 이용하여 풀이.
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int l, c;
	cin >> l >> c;
	vector<int> p(c, 0);                                        //0과 1로 구성된 벡터. l개의 0을 조합을 이용해 암호 만들거
	vector<char> a(c, '\0');                                    //주어진 알파벳을 저장하는 벡터
	vector<char> v = {'a', 'e', 'i', 'o', 'u'};                 //모음 벡터
	for(int i = l; i < c; i++) p[i] = 1;                        //l개의 0을 제외한 모든 원소를 1로 변환
	for(int i = 0; i < c; i++) cin >> a[i];                
	sort(a.begin(), a.end());                                   //알파벳을 오름차순으로 정렬
	
	do {                                                        //p벡터로 조합에 맞는 암호 생성.
		int co = 0, vo = 0;                                       //자음의 최소갯수 변수 co, 모음의 최소갯수 변수 vo
		bool ok = false;                                          //만들어진 암호는 최소 1개의 모음과 최소 2개의 자음을 가지는가?
		for(int i = 0; i < c; i++){                               //만들어지는 암호가 모음, 자음 각각 몇 개로 구성되어있는가?
			bool isvo = false;                                      //현재 암호 n번째 알파벳이 모음인가? 
			for(int j = 0; j < v.size(); j++) {
				if(a[i] == v[j])isvo = true;
			}
			if(!p[i]){
				if(isvo)vo++;
				else co++;
			}
		}
		if(vo >= 1 && co >= 2) ok = true;                         //최소 1개의 모음, 2개의 자음이면 true 반환
		if(ok) {                                                  //최종적으로 나온 암호 
			for(int i = 0; i < c; i++) if(!p[i]) cout << a[i];
			cout << '\n';
		}
	} while(next_permutation(p.begin(), p.end()));
	
	return 0;
}
