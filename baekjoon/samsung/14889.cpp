#include <iostream>
#include <vector>
using namespace std;

int N;
int board[21][21];
bool visited[21];
int min_v = 100;

void dfs(int curr, int depth) {
	if (depth == N / 2) {
		vector<int> start, link;
		int diff = 0;

		for (int i = 0; i < N; i++) {
			if (visited[i])
				start.push_back(i);
			else
				link.push_back(i);
		}

		for (int i = 0; i < N / 2; i++) {
			for (int j = i+1; j < N / 2; j++) {
				diff += board[start[i]][start[j]];
				diff += board[start[j]][start[i]];
				diff -= board[link[i]][link[j]];
				diff -= board[link[j]][link[i]];
			}
		}
		if (diff < 0) diff *= -1;
		min_v = min_v < diff ? min_v : diff;
	}
	else {
		for (int i = curr+1; i < N; i++) {
			if (visited[i]) continue;
			visited[i] = true;
			dfs(i, depth + 1);
			visited[i] = false;
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
	dfs(-1, 0);
	cout << min_v;

	return 0;
}