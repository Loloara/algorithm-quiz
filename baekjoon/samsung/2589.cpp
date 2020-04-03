#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int N, M, answer;
char board[50][50];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

struct node {
	int x, y, dst;
	node(int a, int b, int c) : x(a), y(b), dst(c) {};
};

void initData() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
}

bool safe(int x, int y) {
	return min(x, y) >= 0 && x < N&& y < M;
}

int bfs(int x, int y) {
	bool visited[50][50] = { false };
	queue<node> q;
	q.push(node(x, y, 0));
	visited[x][y] = true;
	int dst = 0;

	while (!q.empty()) {
		node now = q.front();
		dst = now.dst;		
		q.pop();
		for (int i = 0; i < 4; i++) {
			int newX = now.x + dx[i];
			int newY = now.y + dy[i];
			if (!safe(newX, newY)) continue;
			if (board[newX][newY] == 'W') continue;
			if (visited[newX][newY]) continue;
			visited[newX][newY] = true;
			q.push(node(newX, newY, dst + 1));
		}
	}

	return dst;
}

void solution() {
	initData();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) if (board[i][j] == 'L') {
			int dst = bfs(i, j);
			if (answer < dst) {
				answer = dst;
			}
		}
	}
	cout << answer;
}

int main() {
	solution();

	return 0;
}