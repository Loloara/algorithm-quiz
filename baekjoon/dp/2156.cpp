//2156 포도주 시식 https://www.acmicpc.net/problem/2156
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int A[10001];
int mem[10001][3];
int go(int index, int stat);

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> A[i];

	memset(mem, -1, sizeof(mem));
	mem[1][0] = 0;
	mem[1][1] = A[1];
	mem[1][2] = 0;

	cout << max(max(go(n, 0), go(n, 1)), go(n, 2));

	return 0;
}

int go(int index, int stat) {
	if (mem[index][stat] != -1) return mem[index][stat];

	if (stat == 0)
		mem[index][stat] = max(max(go(index - 1, 0), go(index - 1, 1)), go(index - 1, 2));
	else if (stat == 1)
		mem[index][stat] = go(index - 1, 0) + A[index];
	else if (stat == 2)
		mem[index][stat] = go(index - 1, 1) + A[index];

	return mem[index][stat];
}