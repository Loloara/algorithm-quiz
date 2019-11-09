#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	int chess[51][51] = { 0 };
	char board[51][51];
	int rst = INT32_MAX;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if ((i + j) % 2 == 0 && board[i][j] == 'W') chess[i][j]++;
			else if ((i + j) % 2 == 1 && board[i][j] == 'B') chess[i][j]++;
		}
	}

	for (int i = 0; i + 7 < N; i++) {
		for (int j = 0; j + 7 < M; j++) {

			int val = 0;
			for (int x = i; x < i + 8; x++)
				for (int y = j; y < j + 8; y++)
					val += chess[x][y];

			val = val < 32 ? val : 64 - val;
			rst = val < rst ? val : rst;
		}
	}

	cout << rst;

	return 0;
}