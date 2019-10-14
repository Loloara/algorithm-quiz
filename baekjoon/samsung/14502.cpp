#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int wall;
queue<pair<int, int>> virus;
vector<pair<int, int>> suspect;
int x_dir[4] = { 0,0,1,-1 };
int y_dir[4] = { 1,-1,0,0 };
int max_v;

int MAX(int a, int b) { return a > b ? a : b; }

int spread_virus(vector<vector<int>> board) {
	queue<pair<int, int>> q(virus);
	int count = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		count++;
		for (int i = 0; i < 4; i++) {
			int new_x = x + x_dir[i];
			int new_y = y + y_dir[i];
			if (new_x < 0 || new_y < 0 || new_x >= N || new_y >= M) continue;
			if (board[new_x][new_y]) continue;
			board[new_x][new_y] = 2;
			q.push(make_pair(new_x, new_y));
		}
	}

	return (N * M - (wall + count));
}

void dfs(vector<vector<int>> board, int num, int depth) {
	int x = suspect[num].first;
	int y = suspect[num].second;
	board[x][y] = 1;

	if (depth == 3) {
		max_v = MAX(max_v, spread_virus(board));
		return;
	}

	for (int i = num + 1; i < suspect.size(); i++)
		dfs(board, i, depth + 1);
}

int main() {
	vector<vector<int>> board;
	int tmp;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		vector<int> vTmp;
		for (int j = 0; j < M; j++) {
			cin >> tmp;
			vTmp.push_back(tmp);
			if (tmp == 2) virus.push(make_pair(i, j));
			if (tmp == 1) wall++;
			else suspect.push_back(make_pair(i, j));
		}
		board.push_back(vTmp);
	}
	wall += 3;
	
	for (int i = 0; i < suspect.size() - 2; i++)
		dfs(board, i, 1);

	cout << max_v;

	return 0;
}