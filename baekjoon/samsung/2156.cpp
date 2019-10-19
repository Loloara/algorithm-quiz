#include <iostream>
using namespace std;

int MAX(int a, int b, int c) {
	int max_v = a;
	if (max_v < b) max_v = b;
	if (max_v < c) max_v = c;
	return max_v;
}

int main() {
	int N;
	int dp[10001][3] = { 0 };
	int num[10001];

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	dp[0][0] = 0;
	dp[0][1] = num[0];
	dp[0][2] = 0;
	
	for (int i = 1; i < N; i++) {
		dp[i][2] = dp[i - 1][1] + num[i];
		dp[i][1] = dp[i - 1][0] + num[i];
		dp[i][0] = MAX(dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]);
	}

	cout << MAX(dp[N - 1][0], dp[N - 1][1], dp[N - 1][2]);
	
	return 0;
}