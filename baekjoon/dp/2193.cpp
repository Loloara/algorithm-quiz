//2193 ÀÌÄ£¼ö https://www.acmicpc.net/problem/2193
//D[N, last] = D[N-1, 0] + D[N-1, 1]
//O(N)
#include <iostream>
#include <cstring>
using namespace std;

long long mem[91][2];
long long go(int index, int last);

int main() {
	int N;
	memset(mem, -1, sizeof(mem));
	mem[1][0] = 0;
	mem[1][1] = 1;

	cin >> N;
	cout << go(N, 0) + go(N, 1);

	return 0;
}
long long go(int index, int last) {
	if (mem[index][last] != -1) return mem[index][last];
	if (last == 1)
		mem[index][last] = go(index - 1, 0);
	else
		mem[index][last] = go(index - 1, 0) + go(index - 1, 1);

	return mem[index][last];
}