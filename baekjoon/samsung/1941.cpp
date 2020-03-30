#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

char board[5][5];
vector<int> state(25, 0);
int answer = 0;
int perm[5][5];
bool visited[5][5];
int dir_x[4] = { 0,0,-1,1 };
int dir_y[4] = { 1,-1,0,0 };

void initData() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < 7; i++) {
		state[24 - i] = 1;
	}
}

bool safe(int x, int y) {
	return min(x, y) >= 0 && max(x, y) < 5;
}

int dfs(int x, int y) {
	visited[x][y] = true;
	int ret = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dir_x[i];
		int ny = y + dir_y[i];
		if (safe(nx, ny) && !visited[nx][ny] && perm[nx][ny]) {
			ret += dfs(nx, ny);
		}
	}
	return ret;
}

void solution() {
	initData();

	do {
		memset(perm, 0, sizeof(perm));
		int cnt = 0;
		int sx, sy;
		for (int i = 0; i < 25; i++) {
			int x = i / 5;
			int y = i % 5;;
			perm[x][y] = state[i];
			if (state[i]) {
				if (board[x][y] == 'S') {
					cnt++;
				}
				sx = x;
				sy = y;
			}
		}
		if (cnt < 4) continue;
		memset(visited, 0, sizeof(visited));
		answer += dfs(sx, sy) == 7;
	} while (next_permutation(state.begin(), state.end()));

	cout << answer;
}

int main() {
	solution();

	return 0;
}