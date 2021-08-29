#include <iostream>                    
#include <queue>
#include <algorithm>
using namespace std;
bool desc(int a, int b){ 
  return a > b; 
} 

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, m, num_n = 0, r = 1;           
		cin >> n >> m;
		
		int in[101] = {0}, num[101] = {0};    //수를 입력받는 in 배열, 중요도를 정렬해놓은 num 배열
		queue<int> order, im;                 //order : 순서를 나타내는 큐, im : 중요도를 나타내는 큐
		
		for(int i = 0; i < n; i++){
			cin >> in[i];
			num[i] = in[i];
			order.push(i);  
			im.push(in[i]);
		}
		sort(num, num + n, desc);             //입력받은 num 배열을 내림차순으로 정렬
		while(1) {
			if(im.front() != num[num_n]) {      //인쇄하고자 하는 문서의 중요도가 최상위가 아닐 때
				im.push(im.front());
				im.pop();
				order.push(order.front());
				order.pop();
			}
			else { 
				if(order.front() == m) break;     //중요도가 현재 최상위이며 뽑고자 하는 문서일 때
				else {
					order.pop();
					im.pop();
					num_n++;
					r++;
				}
			}
		}
		cout << r << '\n'; 
		
	}
	return 0;
}
