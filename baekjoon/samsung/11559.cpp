#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

char board[12][6];
bool chkBoard[12][6];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
bool keep;
int answer = 0;

void initData() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> board[i][j];
		}
	}
}

bool safe(int x, int y) {
	return min(x, y) >= 0 && x < 12 && y < 6;
}

void bfs(queue<pair<int,int>> q) {
	vector<pair<int, int>> puyos;
	puyos.push_back(make_pair(q.front().first, q.front().second));
	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			if (!safe(nx, ny)) continue;
			if (chkBoard[nx][ny]) continue;
			if (board[now.first][now.second] != board[nx][ny]) continue;
			chkBoard[nx][ny] = true;
			q.push(make_pair(nx, ny));
			puyos.push_back(make_pair(nx, ny));
		}
	}
	if (puyos.size() >= 4) {
		keep = true;
		for (pair<int, int> now : puyos) {
			board[now.first][now.second] = '.';
		}
	}
}

void setBoard() {
	for (int i = 0; i < 6; i++) {
		int pos = -1;
		for (int j = 11; j >= 0; j--) {
			if (board[j][i] == '.') {
				if (pos < 0) {
					pos = j;
				}
			}
			else {
				if (pos >= 0) {
					board[pos][i] = board[j][i];
					board[j][i] = '.';
					j = pos;
					pos = -1;
				}
			}
		}
	}
}

void checkTheBoard() {
	memset(chkBoard, 0, sizeof(chkBoard));
	queue<pair<int, int>> q;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) if(board[i][j] != '.' && !chkBoard[i][j]) {
			chkBoard[i][j] = true;
			q.push(make_pair(i, j));
			bfs(q);
			q.pop();
		}
	}
	setBoard();
}

void solution() {
	initData();
	do {
		keep = false;
		checkTheBoard();
		if (keep) answer++;
	} while (keep);
	cout << answer;
}

int main() {
	solution();

	return 0;
}