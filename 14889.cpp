#include <iostream>
#include <vector>
using namespace std;
int n;
int s[20][20];
int team(int idx, vector<int> &start, vector<int> &link) {
	if(start.size() > n / 2 || link.size() > n / 2) return -1;   //각 팀에 n / 2명을 초과했을 시 조건 불응
  
	if(idx == n) {                                               //성공적으로 n명이 팀에 다 들어가면
		int s1 = 0, s2 = 0, re;
		for(int i = 0; i < n / 2; i++) {                           //start팀, link팀 능력치를 s1, s2에 넣는다.
			for(int j = 0; j < n / 2; j++) {
				s1 += s[start[i]][start[j]];
				s2 += s[link[i]][link[j]];
			}
		}
		re = s1 - s2;                                              //팀 간 능력치 차를 반환
		if(re > 0) return re;
		else return -re;
	}
  
	int a = -1;
	start.push_back(idx);                                        //i번째 선수를 start팀에 영입했을 때
	int p1 = team(idx + 1, start, link);
	if(a == -1 || (p1 != -1 && a > p1)) a = p1;
	start.pop_back();
  
	link.push_back(idx);                                         //i번째 선수를 link팀에 영입했을 때
	int p2 = team(idx + 1, start, link);
	if(a == -1 ||  (p2 != -1 && a > p2)) a = p2;
	link.pop_back();
	return a;
}
int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) cin >> s[i][j];
	}
	vector<int> start, link;
	int re = team(0, start, link);
	cout << re;
	return 0;
}
