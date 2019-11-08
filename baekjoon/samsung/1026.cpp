#include <iostream>
#include <algorithm>
using namespace std;

bool comp(const int& a, const int& b) {
	return a > b ? true : false;
}

int main() {
	int N;
	int A[51];
	int B[51];

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}

	sort(A, A + N);
	sort(B, B + N, comp);

	int sum = 0;
	int min_v = 999;
	for (int i = 0; i < N; i++)
		sum += A[i] * B[i];
	
	cout << sum;

	return 0;
}