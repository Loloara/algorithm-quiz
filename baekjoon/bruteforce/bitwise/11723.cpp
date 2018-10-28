//11723 집합 https://www.acmicpc.net/problem/11723
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);	//iostream stdio 버퍼 동기화 해제
	cin.tie(nullptr);					//cout과 cin tie 기능 해제

	int n, in;
	int arr=0;
	string op;
	cin >> n;
	while (n--) {
		cin >> op;
		if (op.compare("add") == 0) {
			cin >> in;
			arr |= (1<<in);
		}
		else if (op.compare("remove") == 0) {
			cin >> in;
			arr &= ~(1<<in);
		}
		else if (op.compare("check") == 0) {
			cin >> in;
			if ((arr & (1<<in)) == 0)
				cout << 0 << '\n';
			else
				cout << 1 << '\n';
		}
		else if (op.compare("toggle") == 0) {
			cin >> in;
			arr ^= (1<<in);
		}
		else if (op.compare("all") == 0) {
			arr |= (1<<21)-1;
		}
		else if (op.compare("empty") == 0) {
			arr = 0;
		}
	}

	return 0;
}