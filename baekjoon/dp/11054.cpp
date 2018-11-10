//11054 가장 긴 바이토닉 부분 수열 https://www.acmicpc.net/problem/11054
#include <iostream>
using namespace std;

int N;
int A[1001];
int incM[1001] = { 0 };
int decM[1001] = { 0 };

int goInc(int index);
int goDec(int index);

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	incM[1] = 1;
	decM[N] = 1;

	goInc(N);
	goDec(1);

	int max = 0;
	for (int i = 1; i <= N; i++)
		if (max < incM[i] + decM[i] - 1) max = incM[i] + decM[i] - 1;

	cout << max;

	return 0;
}

int goInc(int index) {
	if (incM[index]) return incM[index];

	for (int i = 1; i < index; i++) {
		int val = goInc(i);
		if (A[i] >= A[index]) continue;
		if (incM[index] < incM[i]) incM[index] = incM[i];
	}
	incM[index] += 1;

	return incM[index];
}

int goDec(int index) {
	if (decM[index]) return decM[index];

	for (int i = N; i > index; i--) {
		int val = goDec(i);
		if (A[i] >= A[index]) continue;
		if (decM[index] < decM[i]) decM[index] = decM[i];
	}
	decM[index] += 1;

	return decM[index];
}