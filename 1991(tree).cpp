#include <iostream>
using namespace std;

struct Node {   // 노드 구조체 생성
	int left;
	int right;
};
Node a[27];

void preorder(int x) {    // 전위 순회, 자식의 값을 구해야 할 때 부모의 값을 이용해야 한다면.
	if (x == -1) return;
	cout << (char)(x + 'A');
	preorder(a[x].left);
	preorder(a[x].right);
}
void inorder(int x) {     // 중위 순회
	if (x == -1) return;
	inorder(a[x].left);
	cout << (char)(x + 'A');
	inorder(a[x].right);
}
void postorder(int x) {   // 후위 순회, 현재 노드 값을 구할 때 자식의 값을 이용해야 한다면.
	if (x == -1) return;
	postorder(a[x].left);
	postorder(a[x].right);
	cout << (char)(x + 'A');
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {    // 트리 생성. 노드 배열 안에 정수를 저장한 뒤 아스키 코드에 따른 영어 출력
		char x, y, z;
		cin >> x >> y >> z;
		x = x - 'A';
		if (y == '.') a[x].left = -1;
		else a[x].left = y - 'A';
		if (z == '.') a[x].right = -1;
		else a[x].right = z - 'A';
	}
	preorder(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	postorder(0);
	cout << '\n';
	return 0;
}

