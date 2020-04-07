#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, answer = 1;
int MAX = 0;
int MIN = 101;
int board[100][100];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void initData() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			MAX = max(MAX, board[i][j]);
			MIN = min(MIN, board[i][j]);
		}
	}
}

bool safe(int x, int y) {
	return min(x, y) >= 0 && max(x, y) < N;
}

void bfs(int rain) {
	queue<pair<int, int>> q;
	int cnt = 0;
	bool visited[100][100] = { false };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) if (board[i][j] > rain && !visited[i][j]) {
			q.push(make_pair(i, j));
			visited[i][j] = true;
			cnt++;
			while (!q.empty()) {
				pair<int, int> now = q.front();
				q.pop();
				for (int i = 0; i < 4; i++) {
					int nx = now.first + dx[i];
					int ny = now.second + dy[i];
					if (!safe(nx, ny)) continue;
					if (visited[nx][ny]) continue;
					if (board[nx][ny] <= rain) continue;
					visited[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	if (answer < cnt) answer = cnt;
}

void solution() {
	initData();
}

int main() {
	solution();
	for (int i = MIN; i < MAX; i++) {
		bfs(i);
	}
	cout << answer;

	return 0;
}