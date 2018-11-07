//16194 카드 구매하기2 https://www.acmicpc.net/problem/16194
#include <iostream>
using namespace std;

int mem[1001] = { 0 };
int P[1001];
int go(int index);

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> P[i];

	cout << go(N);

	return 0;
}

int go(int index) {
	if (mem[index] != 0) return mem[index];
	if (index == 0) return 0;

	int min = 10000000;
	for (int i = 1; i <= index; i++) {
		int tmp = go(index - i) + P[i];
		if (tmp < min) min = tmp;
	}
	mem[index] = min;

	return mem[index];
}