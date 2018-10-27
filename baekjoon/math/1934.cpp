//1934 최소공배수 https://www.acmicpc.net/problem/1934
#include <iostream>
using namespace std;

int GCD(int a, int b);

int main() {
	int n;
	int nArr[1000][2];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> nArr[i][0] >> nArr[i][1];
		int gcd = GCD(nArr[i][0], nArr[i][1]);
		cout << nArr[i][0] * nArr[i][1] / gcd << '\n';
	}

	return 0;
}

int GCD(int a, int b) {
	if (b == 0) return a;
	return GCD(b, a%b);
}