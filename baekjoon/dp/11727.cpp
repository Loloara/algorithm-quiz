//11727 2xn ≈∏¿œ∏µ2 https://www.acmicpc.net/problem/11727
#include <iostream>
using namespace std;

int mem[1001] = { 0 };
int go(int index);

int main() {
	int n;
	mem[1] = 1;
	mem[2] = 3;

	cin >> n;
	cout << go(n);

	return 0;
}

int go(int index) {
	if (mem[index] != 0) return mem[index];
	mem[index] = (go(index - 1) % 10007 + 2 * (go(index - 2) % 10007) % 10007) % 10007;

	return mem[index];
}