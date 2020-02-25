#include <iostream>
#include <vector>
using namespace std;

int N;
int loop;
int board[10][10];
int answer = INT32_MAX;;
int dir_x[] = { 0,0,0,0,0,1,2,-1,-2,1,1,-1,-1 };
int dir_y[] = { 0,1,2,-1,-2,0,0,0,0,-1,1,1,-1 };

void dfs(vector<vector<bool>> visited, int index, int depth, int val) {
	if (depth == 3) {
		if (answer > val)
			answer = val;

		return;
	}

	int a = index / 10;
	int b = index % 10;

	for (int i = 0; i < 13; i++) {
		int new_a = a + dir_x[i];
		int new_b = b + dir_y[i];
		if (new_a < 1 || new_b < 1 || new_a >= N - 1 || new_b >= N - 1) continue;

		visited[new_a][new_b] = true;
	}

	for (int i = index + 1; i <= loop; i++) {
		a = i / 10;
		b = i % 10;
		if (a < 1 || b < 1 || a >= N - 1 || b >= N - 1) continue;
		if (visited[a][b]) continue;

		dfs(visited, a * 10 + b, depth + 1, val + board[a][b]);
	}
}

int main() {
	int board_tmp[10][10];

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board_tmp[i][j];
		}
	}

	for (int i = 1; i < N - 1; i++) {
		for (int j = 1; j < N - 1; j++) {
			board[i][j] = board_tmp[i][j] + board_tmp[i - 1][j] + board_tmp[i][j - 1] + board_tmp[i + 1][j] + board_tmp[i][j + 1];
		}
	}


	vector<vector<bool>> visited(N,vector<bool>(N, false));
	loop = 10 * (N - 1) + N - 1;
	for (int index = 11; index <= loop; index++) {
		int a = index / 10;
		int b = index % 10;
		if (a < 1 || b < 1 || a >= N - 1 || b >= N - 1) continue;

		dfs(visited, index, 1, board[a][b]);
	}

	cout << answer;

	return 0;
}