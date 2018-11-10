//13398 연속합2 https://www.acmicpc.net/problem/13398
//for문으로 DP 구현
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	int A[100001];
	int memL[100001];
	int memR[100001];

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	for (int i = 1; i <= N; i++) {
		int j = N - i + 1;
		memL[i] = A[i];
		memR[j] = A[j];
		if (i == 1) continue;
		if (memL[i] < memL[i - 1] + A[i]) memL[i] = memL[i - 1] + A[i];
		if (memR[j] < memR[j + 1] + A[j]) memR[j] = memR[j + 1] + A[j];
	}
	
	int ans = memL[1];
	for (int i = 2; i < N; i++) {
		ans = max({ ans, memL[i - 1] + memR[i + 1],memL[i] });
	}
	if (ans < memL[N]) ans = memL[N];

	cout << ans;

	return 0;
}
