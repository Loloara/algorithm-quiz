//11726 2xn ≈∏¿œ∏µ https://www.acmicpc.net/problem/11726
//D[N] = D[N-1] + D[N-2]
//O(N)
#include <iostream>
using namespace std;

int mem[1001] = { 0 };
int go(int index);

int main() {
	int n;
	mem[1] = 1;
	mem[2] = 2;

	cin >> n;
	cout << go(n);

	return 0;
}

int go(int index) {
	if (mem[index] != 0) return mem[index];
	mem[index] = (go(index - 1) % 10007 + go(index - 2) % 10007) % 10007;

	return mem[index];
}