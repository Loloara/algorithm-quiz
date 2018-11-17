//11053 가장 긴 증가하는 부분 수열 https://www.acmicpc.net/problem/11053
//D[N] = max(D[i]) + 1
// 0 <= i < N
//O(N)
#include <iostream>
using namespace std;

int A[1001];
int mem[1001] = { 0 };

int go(int index);

int main() {
	int N, num;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	mem[1] = 1;

	go(N);

	int max = 0;
	for (int i = 1; i <= N; i++) 
		if (max < mem[i]) max = mem[i];

	cout << max;

	return 0;
}

int go(int index) {
	if (mem[index]) return mem[index];

	for (int i = 1; i < index; i++) {
		int val = go(i);
		if (A[i] >= A[index]) continue;
		if (mem[index] < mem[i]) mem[index] = mem[i];
	}
	mem[index] += 1;

	return mem[index];
}