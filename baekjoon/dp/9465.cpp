//9465 스티커 https://www.acmicpc.net/problem/9465
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int st[1000001][2];
int mem[1000001][3];	//0: 안고른 경우, 1: 위쪽 카드 고른 경우, 2: 아래쪽 카드 고른 경우
int go(int index, int last);

int main() {
	int t, n;
	cin >> t;
	while (t--) {
		memset(mem, -1, sizeof(mem));
		cin >> n;
		for (int i = 0; i < 2; i++)
			for (int j = 1; j <= n; j++)
				cin >> st[j][i];
		mem[1][0] = 0;
		mem[1][1] = st[1][0];
		mem[1][2] = st[1][1];

		cout << max(go(n, 1), go(n, 2)) << '\n';
	}

	return 0;
}

int go(int index, int last) {
	if (mem[index][last] != -1) return mem[index][last];
	if (last == 0) {
		mem[index][last] = max(go(index - 1, 1), go(index - 1, 2));
	}
	else if (last == 1) {
		mem[index][last] = max(go(index - 1, 0), go(index - 1, 2)) + st[index][0];
	}
	else if (last == 2) {
		mem[index][last] = max(go(index - 1, 0), go(index - 1, 1)) + st[index][1];
	}

	return mem[index][last];
}