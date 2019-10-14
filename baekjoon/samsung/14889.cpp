#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	int perm[21];
	int board[21][21];
	int min_v = 100;

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
		perm[i] = i;
	}

	int facto = 1;
	for (int i = N; i > 1; i--)
		facto *= N;
	facto /= 2;
	int num = 1;
	while(num++ != facto) {
		int diff = 0;
		for (int i = 0; i < (N / 2) - 1; i++) {
			for (int j = i + 1; j < N / 2; j++) {
				diff += board[perm[i]][perm[j]];
				diff += board[perm[j]][perm[i]];
			}
		}

		for (int i = N / 2; i < N - 1; i++) {
			for (int j = i + 1; j < N; j++) {
				diff -= board[perm[i]][perm[j]];
				diff -= board[perm[j]][perm[i]];
			}
		}
		if (diff < 0) diff *= -1;
		min_v = min_v < diff ? min_v : diff;
		next_permutation(perm, perm + N);
	}
	cout << min_v;

	return 0;
}