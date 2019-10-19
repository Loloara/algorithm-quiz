#include <iostream>
#include <queue>
using namespace std;

struct tomato {
	int x, y, z;
	tomato(int x, int y, int z) { this->x = x; this->y = y; this->z = z; }
};

int dx[6] = { 0,0,-1,1,0,0 };
int dy[6] = { 1,-1,0,0,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

int board[101][101][101];
int dist[101][101][101] = { 0 };
bool visited[101][101][101] = { false };

int main() {
	int M, N, H;
	cin >> M >> N >> H;

	int total = 0;
	queue<tomato> q;

	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> board[i][j][k];
				if (board[i][j][k] == 1) {
					q.push(tomato(i, j, k));
					visited[i][j][k] = true;
				}
				else if (board[i][j][k] == 0) {
					total++;
				}
			}
		}
	}

	if (!total) {
		cout << 0;
		return 0;
	}
	if (!q.size()) {
		cout << -1;
		return 0;
	}

	while (!q.empty()) {
		tomato now = q.front();
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];
			int nz = now.z + dz[i];
			if (nx < 0 || ny < 0 || nz < 0 || nx >= N || ny >= M || nz >= H)
				continue;
			if (board[nx][ny][nz] == -1) continue;
			if (visited[nx][ny][nz]) continue;
			if (!board[nx][ny][nz]) {
				board[nx][ny][nz] = 1;
				dist[nx][ny][nz] = dist[now.x][now.y][now.z] + 1;
				visited[nx][ny][nz] = true;
				q.push(tomato(nx, ny, nz));
				total--;
			}
		}

		if (!total) {
			cout << dist[now.x][now.y][now.z] + 1;
			return 0;
		}
	}

	cout << -1;

	return 0;
}