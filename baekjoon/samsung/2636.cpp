#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N, M, total=0;
	int board[101][101];

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) total++;
		}
	}

	int dead, count = 0;
	queue<pair<int, int>> q;
	int dx[4] = { 0,0,-1,1 };
	int dy[4] = { 1,-1,0,0 };
	while (total) {
		count++;
		bool visited[101][101] = { false };
		dead = 0;
		q.push({ 0,0 });
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int new_x = x + dx[i];
				int new_y = y + dy[i];
				if (new_x < 0 || new_y < 0 || new_x >= N || new_y >= M) continue;
				if (board[new_x][new_y] == 1 || visited[new_x][new_y]) continue;
				visited[new_x][new_y] = true;
				board[new_x][new_y] = 2;
				q.push({ new_x, new_y });
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (board[i][j] != 2) continue;

				for (int d = 0; d < 4; d++) {
					int new_x = i + dx[d];
					int new_y = j + dy[d];
					if (new_x < 0 || new_y < 0 || new_x >= N || new_y >= M) continue;
					if (board[new_x][new_y] == 1) {
						board[new_x][new_y] = 0;
						dead++;
					}
				}
			}
		}
		total -= dead;
	}
	
	cout << count << endl << dead;

	return 0;
}