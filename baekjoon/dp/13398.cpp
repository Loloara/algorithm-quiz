//13398 ¿¬¼ÓÇÕ2 https://www.acmicpc.net/problem/13398
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[100001];
int mem[100001] = { 0 };
int ans[100001] = { 0 };
int dpL(int index);
int dpR(int index);

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	mem[1] = A[1];
	mem[N] = A[N];

	for (int i = 0; i <= N; i++) {
		int maxM = dpL(i - 1) + dpR(i + 1);
		int maxL = -100000001; 
		int maxR = -100000001;
		if (i > 1)
			maxL = *max_element(mem + 1, mem + i - 1);
		if (i < N)
			maxR = *max_element(mem + i + 1, mem + N);
		ans[i] = max(max(maxL, maxR), maxM);	
		mem[i] = 0;
	}

	cout << *max_element(ans, ans + N);

	return 0;
}

int dpL(int index) {
	if (index <= 0) return -100000001;
	if (mem[index]) return mem[index];
	mem[index] = max(A[index], dpL(index - 1) + A[index]);

	return mem[index];
}

int dpR(int index) {
	if (index > N) return -100000001;
	if (mem[index]) return mem[index];
	mem[index] = max(A[index], dpR(index + 1) + A[index]);

	return mem[index];
}