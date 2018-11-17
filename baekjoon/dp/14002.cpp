//14002 가장 긴 증가하는 부분 수열4 https://www.acmicpc.net/problem/14002
//D[N] = max(D[i]) + 1
// 0 <= i < N
//O(N^2)
#include <iostream>
#include <stack>
using namespace std;

int A[1001];
int mem[1001] = { 0 };
int trace[1001] = { 0 };

int go(int index);

int main() {
	int N, num;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	mem[1] = 1;

	go(N);

	int max[2] = { 0 };
	for (int i = 1; i <= N; i++) {
		if (max[0] < mem[i]) {
			max[0] = mem[i];
			max[1] = i;
		}
	}

	int index = max[1];
	stack<int> st;
	while (index) {
		st.push(index);
		index = trace[index];
	}

	cout << max[0] << '\n';
	while (!st.empty()) {
		cout << A[st.top()] << ' ';
		st.pop();
	}

	return 0;
}

int go(int index) {
	if (mem[index]) return mem[index];

	for (int i = 1; i < index; i++) {
		int val = go(i);
		if (A[i] >= A[index]) continue;
		if (mem[index] < mem[i]) {
			mem[index] = mem[i];
			trace[index] = i;
		}
	}
	mem[index] += 1;

	return mem[index];
}