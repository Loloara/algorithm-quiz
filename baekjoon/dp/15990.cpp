//15990 1,2,3 ���ϱ�5 https://www.acmicpc.net/problem/15990
//D[N][1] = D[N-1][2] + D[N-1][3]
//D[N][2] = D[N-1][1] + D[N-1][3]
//D[N][3] = D[N-1][1] + D[N-1][2]
//O(N)
#include <iostream>
#include <cstring>
using namespace std;

const long long DIV = 1000000009;
long long mem[100001][4];		// N�� ����� ���� ���� �ֱٿ� ���� ���� ����Ͽ� ����� ���� ������.
long go(int index, int prev);

int main() {
	int t, n;
	memset(mem, 0, sizeof(mem));
	mem[1][1] = 1;
	mem[2][2] = 1;
	mem[3][3] = 1;

	cin >> t;
	while (t--) {
		cin >> n;
		cout << ((go(n, 1) + go(n, 2)) % DIV + go(n, 3)) % DIV << '\n';
	}

	return 0;
}

long go(int index, int prev) {
	if (index < 0) return 0;
	if (mem[index][prev]) return mem[index][prev];

	for (int i = 1; i <= 3; i++) {	 
		if (i == prev) continue;		// ���ڴ� �������� ���� �� ����.
		mem[index][prev] = (mem[index][prev] + go(index - prev, i)) % DIV;
	}
	
	return mem[index][prev];
}