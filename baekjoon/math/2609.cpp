//2609 최대공약수와 최소공배수 https://www.acmicpc.net/problem/2609
#include <iostream>
using namespace std;

int GCD(int a, int b);

int main() {
	int a, b;
	cin >> a >> b;
	int gcd = GCD(a, b);
	cout << gcd << '\n';
	cout << a * b / gcd;

	return 0;
}

int GCD(int a, int b) {
	if (b == 0) return a;
	return GCD(b, a%b);
}