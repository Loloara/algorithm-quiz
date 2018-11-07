//10844 쉬운 계단 수 https://www.acmicpc.net/problem/10844
#include <iostream>
#include <cstring>
using namespace std;

const long long DIV = 1000000000;
long long mem[101][10];
long long go(int index, int last);

int main() {
	int N;
	long long ans = 0;
	memset(mem, 0, sizeof(mem));
	for (int i = 1; i < 10; i++)
		mem[1][i] = 1;

	cin >> N;
	for (int i = 0; i < 10; i++) {
		ans = (ans + go(N, i)) % DIV;
	}
	cout << ans;

	return 0;
}

long long go(int index, int last) {
	if (index < 1) return 0;
	if (mem[index][last]) return mem[index][last];

	if (last != 9)
		mem[index][last] = (mem[index][last] + go(index - 1, last + 1)) % DIV;
	if (last)
		mem[index][last] = (mem[index][last] + go(index - 1, last - 1)) % DIV;

	return mem[index][last];
}