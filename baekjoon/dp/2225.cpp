//2225 ÇÕºÐÇØ https://www.acmicpc.net/problem/2225
//D[N][K] += D[N - i][K - 1]
//0 <= i <= N
//O(N^2)
#include <iostream>
#include <cstring>
using namespace std;

const int DIV = 1000000000;
int mem[201][201];
int dp(int N, int K);

int main() {
	int N, K;
	memset(mem, 0, sizeof(mem));
	for (int i = 1; i < 201; i++)
		mem[i][1] = 1;
	for (int i = 1; i < 201; i++)
		mem[0][i] = 1;

	cin >> N >> K;
	cout << dp(N, K);

	return 0;
}

int dp(int N, int K) {
	if (mem[N][K]) return mem[N][K];
	for (int i = 0; i <= N; i++)
		mem[N][K] = (mem[N][K] + dp(N - i, K - 1)) % DIV;

	return mem[N][K];
}