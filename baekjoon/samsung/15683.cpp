#include <iostream>
#include <vector>
using namespace std;

int N, M, min_v=65;
vector<pair<int, int>> cam;

void dfs(int index, vector<vector<int>> board, int nonc) {
	if (index == cam.size()) {
		min_v = min_v < nonc ? min_v : nonc;
		return;
	}

	int x = cam[index].first;
	int y = cam[index].second;
	vector<vector<int>> a_board(board);
	int a_nonc = nonc;
	vector<vector<int>> b_board(board);
	int b_nonc = nonc;
	vector<vector<int>> c_board(board);
	int c_nonc = nonc;

	if (board[x][y] == 2) { //위아래, 양옆
		for (int i = x + 1; i < N; i++) {
			if (board[i][y] == 6) break;
			if (!board[i][y]) {
				board[i][y] = -1;
				nonc--;
			}
		}
		for (int i = x - 1; i >= 0; i--) {
			if (board[i][y] == 6) break;
			if (!board[i][y]) {
				board[i][y] = -1;
				nonc--;
			}
		}
		for (int i = y + 1; i < M; i++) {
			if (c_board[x][i] == 6) break;
			if (!c_board[x][i]) {
				c_board[x][i] = -1;
				c_nonc--;
			}
		}
		for (int i = y - 1; i >= 0; i--) {
			if (c_board[x][i] == 6) break;
			if (!c_board[x][i]) {
				c_board[x][i] = -1;
				c_nonc--;
			}
		}
		dfs(index + 1, board, nonc);
		dfs(index + 1, c_board, c_nonc);
	}
	else if (board[x][y] == 5) { //네방향
		for (int i = x + 1; i < N; i++) {
			if (board[i][y] == 6) break;
			if (!board[i][y]) {
				board[i][y] = -1;
				nonc--;
			}
		}
		for (int i = x - 1; i >= 0; i--) {
			if (board[i][y] == 6) break;
			if (!board[i][y]) {
				board[i][y] = -1;
				nonc--;
			}
		}
		for (int i = y + 1; i < M; i++) {
			if (board[x][i] == 6) break;
			if (!board[x][i]) {
				board[x][i] = -1;
				nonc--;
			}
		}
		for (int i = y - 1; i >= 0; i--) {
			if (board[x][i] == 6) break;
			if (!board[x][i]) {
				board[x][i] = -1;
				nonc--;
			}
		}
		dfs(index + 1, board, nonc);
	}
	else if (board[x][y] == 1) {	//동,서,남,북
		for (int i = x + 1; i < N; i++) {
			if (board[i][y] == 6) break;
			if (!board[i][y]) {
				board[i][y] = -1;
				nonc--;
			}
		}
		for (int i = x - 1; i >= 0; i--) {
			if (a_board[i][y] == 6) break;
			if (!a_board[i][y]) {
				a_board[i][y] = -1;
				a_nonc--;
			}
		}
		for (int i = y + 1; i < M; i++) {
			if (c_board[x][i] == 6) break;
			if (!c_board[x][i]) {
				c_board[x][i] = -1;
				c_nonc--;
			}
		}
		for (int i = y - 1; i >= 0; i--) {
			if (b_board[x][i] == 6) break;
			if (!b_board[x][i]) {
				b_board[x][i] = -1;
				b_nonc--;
			}
		}
		dfs(index + 1, board, nonc);
		dfs(index + 1, c_board, c_nonc);
		dfs(index + 1, a_board, a_nonc);
		dfs(index + 1, b_board, b_nonc);
	}
	else if (board[x][y] == 3) {
		for (int i = x - 1; i >= 0; i--) {
			if (a_board[i][y] == 6) break;
			if (!a_board[i][y]) {
				a_board[i][y] = -1;
				a_nonc--;
			}
		}
		for (int i = y + 1; i < M; i++) {
			if (a_board[x][i] == 6) break;
			if (!a_board[x][i]) {
				a_board[x][i] = -1;
				a_nonc--;
			}
		}


		for (int i = x + 1; i < N; i++) {
			if (board[i][y] == 6) break;
			if (!board[i][y]) {
				board[i][y] = -1;
				nonc--;
			}
		}
		for (int i = y + 1; i < M; i++) {
			if (board[x][i] == 6) break;
			if (!board[x][i]) {
				board[x][i] = -1;
				nonc--;
			}
		}

		for (int i = x + 1; i < N; i++) {
			if (b_board[i][y] == 6) break;
			if (!b_board[i][y]) {
				b_board[i][y] = -1;
				b_nonc--;
			}
		}
		for (int i = y - 1; i >= 0; i--) {
			if (b_board[x][i] == 6) break;
			if (!b_board[x][i]) {
				b_board[x][i] = -1;
				b_nonc--;
			}
		}

		for (int i = y - 1; i >= 0; i--) {
			if (c_board[x][i] == 6) break;
			if (!c_board[x][i]) {
				c_board[x][i] = -1;
				c_nonc--;
			}
		}
		for (int i = x - 1; i >= 0; i--) {
			if (c_board[i][y] == 6) break;
			if (!c_board[i][y]) {
				c_board[i][y] = -1;
				c_nonc--;
			}
		}

		dfs(index + 1, board, nonc);
		dfs(index + 1, c_board, c_nonc);
		dfs(index + 1, a_board, a_nonc);
		dfs(index + 1, b_board, b_nonc);
	}
	else if (board[x][y] == 4) {
	for (int i = x - 1; i >= 0; i--) {
		if (a_board[i][y] == 6) break;
		if (!a_board[i][y]) {
			a_board[i][y] = -1;
			a_nonc--;
		}
	}
	for (int i = y + 1; i < M; i++) {
		if (a_board[x][i] == 6) break;
		if (!a_board[x][i]) {
			a_board[x][i] = -1;
			a_nonc--;
		}
	}
	for (int i = y - 1; i >= 0; i--) {
		if (a_board[x][i] == 6) break;
		if (!a_board[x][i]) {
			a_board[x][i] = -1;
			a_nonc--;
		}
	}

	for (int i = x + 1; i < N; i++) {
		if (board[i][y] == 6) break;
		if (!board[i][y]) {
			board[i][y] = -1;
			nonc--;
		}
	}
	for (int i = y + 1; i < M; i++) {
		if (board[x][i] == 6) break;
		if (!board[x][i]) {
			board[x][i] = -1;
			nonc--;
		}
	}
	for (int i = x - 1; i >= 0; i--) {
		if (board[i][y] == 6) break;
		if (!board[i][y]) {
			board[i][y] = -1;
			nonc--;
		}
	}

	for (int i = x + 1; i < N; i++) {
		if (b_board[i][y] == 6) break;
		if (!b_board[i][y]) {
			b_board[i][y] = -1;
			b_nonc--;
		}
	}
	for (int i = y - 1; i >= 0; i--) {
		if (b_board[x][i] == 6) break;
		if (!b_board[x][i]) {
			b_board[x][i] = -1;
			b_nonc--;
		}
	}
	for (int i = y + 1; i < M; i++) {
		if (b_board[x][i] == 6) break;
		if (!b_board[x][i]) {
			b_board[x][i] = -1;
			b_nonc--;
		}
	}

	for (int i = y - 1; i >= 0; i--) {
		if (c_board[x][i] == 6) break;
		if (!c_board[x][i]) {
			c_board[x][i] = -1;
			c_nonc--;
		}
	}
	for (int i = x - 1; i >= 0; i--) {
		if (c_board[i][y] == 6) break;
		if (!c_board[i][y]) {
			c_board[i][y] = -1;
			c_nonc--;
		}
	}
	for (int i = x + 1; i < N; i++) {
		if (c_board[i][y] == 6) break;
		if (!c_board[i][y]) {
			c_board[i][y] = -1;
			c_nonc--;
		}
	}

	dfs(index + 1, board, nonc);
	dfs(index + 1, c_board, c_nonc);
	dfs(index + 1, a_board, a_nonc);
	dfs(index + 1, b_board, b_nonc);
	}
}

int main() {
	vector<vector<int>> board;
	int nonc = 0;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		vector<int> vTmp;
		for (int j = 0; j < M; j++) {
			int tmp;
			cin >> tmp;
			if (!tmp) nonc++;

			if (tmp > 0 && tmp < 6)
				cam.push_back(make_pair(i, j));
			vTmp.push_back(tmp);
		}
		board.push_back(vTmp);
	}

	min_v = nonc;

	if(cam.size())
		dfs(0, board, nonc);

	cout << min_v;

	return 0;
}