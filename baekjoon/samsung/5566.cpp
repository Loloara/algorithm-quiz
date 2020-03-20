#include <iostream>
using namespace std;

int main() {
	int N, M, dice, pos;
	int board[1001] = { 0 };

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> board[i];
	}

	pos = 1;
	for (int i = 1; i <= M; i++) {
		cin >> dice;
		pos = pos + dice + board[pos + dice];
		if (pos >= N) {
			cout << i;
			break;
		}
	}

	return 0;
}