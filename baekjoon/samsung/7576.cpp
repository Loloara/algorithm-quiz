#include <iostream>
#include <queue>
using namespace std;

struct tomato {
	int x, y;
	tomato(int x, int y) { this->x = x; this->y = y; }
};

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int board[1001][1001];
int dist[1001][1001] = { 0 };
bool visited[1001][1001] = { false };

int main() {
	int M, N, ans=-1;
	cin >> M >> N;

	int total = 0;
	queue<tomato> q;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				q.push(tomato(i, j));
				visited[i][j] = true;
			}
			else if (board[i][j] == 0) {
				total++;
			}
		}
	}

	if (!total) {
		cout << 0;
		return 0;
	} 

	while (!q.empty()) {
		tomato now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M)
				continue;
			if (board[nx][ny] || visited[nx][ny]) continue;
			board[nx][ny] = 1;
			dist[nx][ny] = dist[now.x][now.y] + 1;
			visited[nx][ny] = true;
			q.push(tomato(nx, ny));
			total--;
		}

		if (!total) {
			ans = dist[now.x][now.y] + 1;
			break;
		}
	}

	cout << ans;

	return 0;
}