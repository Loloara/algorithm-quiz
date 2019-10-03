#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, D;
vector<int> shooters;
int x_dir[3] = { 0,-1,0 };
int y_dir[3] = { -1,0,1 };

bool comp(const pair<int, int>& a, const pair<int, int>& b) {
	return a.second < b.second;
}

int solution(vector<vector<int>> board) {
	int ans = 0;
	bool keep = true;
	
	while (keep) {
		keep = false;
		queue<pair<int, int>> q;
		int mem[3][16][16] = { 0 };

		vector<vector<int>> c_board(board);
		for (int i = 0; i < 3; i++) {
			vector < pair<int, int>> enemy;

			q.push(make_pair(N, shooters[i]));
			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				for (int j = 0; j < 3; j++) {
					int new_x = x + x_dir[j];
					int new_y = y + y_dir[j];

					if (new_x < 0 || new_x >= N || new_y < 0 || new_y >= M) continue;
					if (mem[i][new_x][new_y]) continue;
					mem[i][new_x][new_y] = mem[i][x][y] + 1;
					if (enemy.empty()) {
						if (mem[i][new_x][new_y] > D) continue;
						if (c_board[new_x][new_y]) enemy.push_back(make_pair(new_x, new_y));
					}
					else {
						if (mem[i][enemy[0].first][enemy[0].second] < mem[i][new_x][new_y]) continue;
						if (c_board[new_x][new_y]) enemy.push_back(make_pair(new_x, new_y));
					}

					q.push(make_pair(new_x, new_y));
				}
			}
			//enemy »èÁ¦
			if (enemy.empty()) continue;
			sort(enemy.begin(), enemy.end(), comp);
			if (board[enemy[0].first][enemy[0].second]) {
				board[enemy[0].first][enemy[0].second] = 0;
				ans++;
			}
		}

		for (int i = 0; i < M; i++) {
			for (int j = N - 1; j > 0; j--) {
				board[j][i] = board[j - 1][i];
				if (board[j][i]) keep = true;
			}
			board[0][i] = 0;
		}
	}

	return ans;
}

int dfs(vector<vector<int>> board, int index, int depth) {
	if (depth == 3) return solution(board);
	int max = -1;
	for (int i = index + 1; i < M; i++) {
		shooters.push_back(i);
		int tmp = dfs(board, i, depth + 1);
		if (tmp > max) max = tmp;
		shooters.pop_back();
	}

	return max;
}

int main() {
	vector<vector<int>> board;
	int tmp;

	cin >> N >> M >> D;
	for (int i = 0; i < N; i++) {
		vector<int> vTmp;
		for (int j = 0; j < M; j++) {
			cin >> tmp;
			vTmp.push_back(tmp);
		}
		board.push_back(vTmp);
	}

	cout << dfs(board, -1, 0);

	return 0;
}