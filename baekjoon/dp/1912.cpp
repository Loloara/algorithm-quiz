//1912 ¿¬¼ÓÇÕ https://www.acmicpc.net/problem/1912
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[100001];
int mem[100001] = { 0 };
int dp(int index);

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	mem[1] = A[1];

	dp(N);
	cout << *max_element(mem + 1, mem + N + 1);

	return 0;
}

int dp(int index) {
	if (mem[index]) return mem[index];
	mem[index] = max(A[index], dp(index - 1) + A[index]);

	return mem[index];
}