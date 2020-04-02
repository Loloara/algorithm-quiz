#include <iostream>
using namespace std;

int M, N;
bool board[1000][1000];
int answer = 0;

void initData() {
	int tmp;
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			board[i][j] = tmp == 0 ? false : true;
		}
	}
}

bool safe(int x, int y) {
	return x < M&& y < N;
}

void dfs(int x, int y, int cnt) {
	if (!safe(x + cnt, y + cnt)) return;

	int j = y + cnt;
	for (int i = x; i <= x + cnt; i++) {
		if (board[i][j]) return;
	}
	int i = x + cnt;
	for (int j = y; j < y + cnt; j++) {
		if (board[i][j]) return;
	}

	if (++cnt > answer) {
		answer = cnt;
	}
	dfs(x, y, cnt);
}

void solution() {
	initData();
	for (int i = 0; i < M - answer; i++) {
		for (int j = 0; j < N - answer; j++) if (!board[i][j]) {
			if (answer < 1) {
				answer = 1;
			}
			dfs(i, j, 1);
		}
	}

	cout << answer;
}

int main() {
	solution();

	return 0;
}