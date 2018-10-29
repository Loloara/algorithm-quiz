//15650 N과 M(2) https://www.acmicpc.net/problem/15650
#include <iostream>
using namespace std;

bool chk[8] = {};
void go(int n, int m, int index, int cur);

int main() {
	int n, m;
	cin >> n >> m;
	go(n, m, 0, 0);
	return 0;
}

void go(int n, int m, int index, int cur) {
	//정답인 경우
	if (m == cur) {
		for (int i = 0; i < n; i++) {
			if (chk[i])
				cout << i + 1 << ' ';
		}
		cout << '\n';
		return;
	}

	//불가능한 경우
	if (n == index) return;

	//다음 경우
	chk[index] = true;
	go(n, m, index + 1, cur + 1);
	chk[index] = false;
	go(n, m, index + 1, cur);
}