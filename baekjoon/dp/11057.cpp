//11057 오르막 수 https://www.acmicpc.net/problem/11057
#include <iostream>
#include <cstring>
using namespace std;

const int DIV = 10007;
int mem[1001][10];
int go(int index, int last);

int main() {
	int N, ans = 0;
	memset(mem, 0, sizeof(mem));
	for (int i = 0; i < 10; i++)
		mem[1][i] = 1;

	cin >> N;
	for (int i = 0; i < 10; i++)
		ans = (ans + go(N, i)) % DIV;
	cout << ans;

	return 0;
}

int go(int index, int last) {
	if (mem[index][last]) return mem[index][last];
	for (int i = 0; i <= last; i++) {
		mem[index][last] = (mem[index][last] + go(index - 1, i)) % DIV;
	}

	return mem[index][last];
}