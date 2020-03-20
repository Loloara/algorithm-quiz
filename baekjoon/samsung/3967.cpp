#include <iostream>
using namespace std;

int chkLocation[6][4][2] = {{{0,4}, {1,3}, {2,2}, {3,1}},
							{{0,4}, {1,5}, {2,6}, {3,7}},
							{{1,1}, {1,3}, {1,5}, {1,7}}, 
							{{3,1}, {3,3}, {3,5}, {3,7}},
							{{4,4}, {3,3}, {2,2}, {1,1}},
							{{4,4}, {3,5}, {2,6}, {1,7}}};

int remains = 0;
char board[5][9];
pair<int, int> suspect[12];
bool usedNum[12] = { false };

bool checkTheBoard(char board[][9]) {

	for (int i = 0; i < 6; i++) {
		int isTS = 0;
		for (int j = 0; j < 4; j++) {
			isTS += (board[chkLocation[i][j][0]][chkLocation[i][j][1]] - 'A' + 1);
		}
		if (isTS != 26) return false;
	}

	return true;
}

void printBoard(char board[][9]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			cout << board[i][j];
		}
		cout << endl;
	}
}

void dfs(int depth) {
	if (depth == remains) {
		if (checkTheBoard(board)) {
			printBoard(board);
			exit(0);
		}
		return;
	}
	
	for (int i = 0; i < 12; i++) if (!usedNum[i]) {
		board[suspect[depth].first][suspect[depth].second] = i + 'A';
		usedNum[i] = true;
		dfs(depth + 1);
		usedNum[i] = false;
	}
}

void initialData() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'x') {
				suspect[remains++] = make_pair(i, j);
			}
			else if (board[i][j] <= 'L' && board[i][j] >= 'A') {
				usedNum[board[i][j] - 'A'] = true;
			}
		}
	}
}

void solution() {
	initialData();
	dfs(0);
}

int main() {
	solution();

	return 0;
}