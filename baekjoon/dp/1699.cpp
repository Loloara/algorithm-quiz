//1699 제곱수의 합 https://www.acmicpc.net/problem/1699
#include <iostream>
using namespace std;

int mem[100001];
int dp(int index);

int main() {
	int N;
	cin >> N;
	mem[0] = 0;
	mem[1] = 1;
	for (int i = 1; i <= N; i++)
		mem[i] = -1;
	cout << dp(N);

	return 0;
}

int dp(int index) {
	if (mem[index] != -1) return mem[index];
	for (int i = 1; i*i <= index; i++) {
		int num = dp(index - (i * i)) + 1;
		if (mem[index] > num || mem[index] == -1) mem[index] = num;
	}

	return mem[index];
}