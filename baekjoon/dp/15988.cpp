//15988 1,2,3 ¥ı«œ±‚3 https://www.acmicpc.net/problem/15988
//D[N] = D[N-1] + D[N-2] + D[N-3]
//O(N)
#include <iostream>
using namespace std;

const long long DIV = 1000000009LL;
long long mem[1000001] = { 0 };
long long go(int index);

int main() {
	int t, n;
	mem[0] = 1;
	mem[1] = 1;
	mem[2] = 2;

	cin >> t;
	while (t--) {
		cin >> n;
		cout << go(n) << '\n';
	}
	return 0;
}

long long go(int index) {
	if (mem[index] != 0) return mem[index];
	mem[index] = ((go(index - 1) + go(index - 2)) % DIV + go(index - 3)) % DIV;
	
	return mem[index];
}