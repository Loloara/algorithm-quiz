#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int M, N;
int board[500][500];
int visited[500][500];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void initData() {
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	memset(visited, -1, sizeof(visited));
	visited[M - 1][N - 1] = 1;
}

bool safe(int x, int y) {
	return min(x, y) >= 0 && x < M&& y < N;
}

int dp(int x, int y) {
	if (visited[x][y] != -1) return visited[x][y];
	visited[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!safe(nx, ny)) continue;
		if (board[x][y] <= board[nx][ny]) continue;
		visited[x][y] += dp(nx, ny); 
	}
	return visited[x][y];
}

void solution() {
	initData();
	cout << dp(0, 0);
}

int main() {
	solution();

	return 0;
}