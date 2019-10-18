#include <iostream>
#include <queue>
using namespace std;

int N;
int board[101][101];
bool visited[101][101] = { false };
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

typedef struct node {
	int x, y, depth;
	node(int x, int y, int depth) { this->x = x; this->y = y; this->depth = depth; }
};

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (!board[i][j])
				visited[i][j] = true;
		}
	}

	queue<pair<int, int>> q;	//¶¥ ³ª´©±â
	int land = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j]) continue;
			land++;
			q.push(make_pair(i, j));
			board[i][j] = land;
			visited[i][j] = true;
			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				for (int d = 0; d < 4; d++) {
					int new_x = x + dx[d];
					int new_y = y + dy[d];
					if (new_x < 0 || new_y < 0 || new_x >= N || new_y >= N) continue;
					if (visited[new_x][new_y]) continue;
					visited[new_x][new_y] = true;
					board[new_x][new_y] = land;
					q.push(make_pair(new_x, new_y));
				}
			}
		}
	}

	queue<node> nq;
	int min_v = INT32_MAX;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!board[i][j]) continue;
			land = board[i][j];
			int _visited[101][101] = { 0 };
			nq.push(node(i,j,0));

			while (!nq.empty()) {
				int x = nq.front().x;
				int y = nq.front().y;
				int depth = nq.front().depth;
				nq.pop();

				if (depth == min_v) {
					while (!nq.empty()) {
						nq.pop();
					}
					break;
				}

				for (int d = 0; d < 4; d++) {
					int new_x = x + dx[d];
					int new_y = y + dy[d];
					if (new_x < 0 || new_y < 0 || new_x >= N || new_y >= N) continue;
					if (board[new_x][new_y] == land) continue;
					if (!board[new_x][new_y]) {
						if (_visited[new_x][new_y] == 0 || _visited[new_x][new_y] > depth + 1) {
							nq.push(node(new_x, new_y, depth + 1));
							_visited[new_x][new_y] = depth + 1;
						}
					}
					else {
						min_v = depth;
						while (!nq.empty()) {
							nq.pop();
						}
						break;
					}
				}
			}
		}
	}

	cout << min_v;

	return 0;
}