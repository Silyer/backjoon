#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
bool cmp(pair<int, string> a, pair<int, string> b) { // 순서쌍의 첫번째 원소가 작다면 오름차순 정렬
	if(a.first < b.first) return true;
	else return false;      // = return a.first < b.first
}
int main() {
	int n;
	cin >> n;
	pair<int, string> id; //pair id 선언 <나이, 이름>
	vector<pair<int, string>> v;  //pair 컨테이너 vector 선언
	for(int i = 0; i < n; i++) {
		cin >> id.first >> id.second;   //pair 나이, 이름 입력 후
		v.push_back(id);                //벡터에 집어넣는다.
	}
	stable_sort(v.begin(), v.end(), cmp);	//문제의 핵심 - 순서쌍의 첫번째 원소가 작을때만 정렬
	for(int i = 0; i < n; i++) cout << v[i].first << " " << v[i].second << "\n";
	return 0;
}
