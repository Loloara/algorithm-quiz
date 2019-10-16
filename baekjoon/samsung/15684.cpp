#include <iostream>
using namespace std;

bool visited[31][11] = { false };
int N, H, M;
int min_v = 4;

void dfs(int x, int y, int depth) {
	if (depth >= min_v) return;

	bool ans = true;
	for (int j = 1; j <= N; j++) {
		int line = j;
		for (int i = 1; i <= H; i++) {
			if (line < N) {
				if (visited[i][line]) {
					line += 1;
					continue;
				}
			}
			if (line - 1 >= 1) {
				if (visited[i][line - 1]) 
					line -= 1;
			}
		}
		if (j != line) {
			ans = false;
			break;
		}
	}

	if (ans)
		min_v = min_v < depth ? min_v : depth;

	int i = x;
	int j = y + 1;
	if (j > N - 1) {
		i += 1;
		j = 1;
	}
	for (; i <= H; i++) {
		for (; j < N; j++) {
			if (visited[i][j]) continue;
			if (j - 1 > 0) {
				if (visited[i][j - 1]) continue;
			}
			if (j + 1 < N) {
				if (visited[i][j + 1]) continue;
			}
			visited[i][j] = true;
			dfs(i, j, depth + 1);
			visited[i][j] = false;
		}
		j = 1;
	}
}

int main() {
	int x, y;

	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		visited[x][y] = true;
	}

	x = 0; y = 0;
	for (int i = 1; i <= H; i++) {
		if (x != 0 || y != 0) break;
		for (int j = 1; j < N; j++) {
			if (visited[i][j]) continue;
			if (j - 1 >= 1) 
				if (visited[i][j - 1]) continue;
			if (j + 1 < N) 
				if (visited[i][j + 1]) continue;
			x = i; y = j;
			break;
		}
	}

	dfs(x, y - 1, 0);

	if (min_v == 4) min_v = -1;

	cout << min_v;

	return 0;
}