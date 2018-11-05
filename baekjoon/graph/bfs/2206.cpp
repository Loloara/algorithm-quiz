//2206 벽 부수고 이동하기 https://www.acmicpc.net/problem/2206
#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>
using namespace std;

int main() {
	int N, M;
	int nMap[1001][1001];
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%1d", &nMap[i][j]);

	queue<tuple<int, int, int>> Q;
	int dist[1001][1001][2];
	memset(dist, 0, sizeof(dist));
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { -1,0,1,0 };

	Q.push(make_tuple(0, 0, 0));
	dist[0][0][0] = 1;

	while (!Q.empty()) {
		int nodeX, nodeY, nodeZ;
		tie(nodeX, nodeY, nodeZ) = Q.front();
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int newX = nodeX + dx[i];
			int newY = nodeY + dy[i];

			if (newX < 0 || newX >= N || newY < 0 || newY >= M) continue;
			int newZ = nMap[newX][newY] + nodeZ;
			if (newZ > 1) continue;	// nMap과 nodeZ가 모두 1인 경우 스킵한다.
			if (dist[newX][newY][newZ] > 0) continue;
			Q.push(make_tuple(newX, newY, newZ));
			dist[newX][newY][newZ] = dist[nodeX][nodeY][nodeZ] + 1;
		}
	}

	if (dist[N - 1][M - 1][0] == 0 && dist[N - 1][M - 1][1] == 0) {
		cout << -1;
	}
	else if (dist[N - 1][M - 1][0] == 0) {
		cout << dist[N - 1][M - 1][1];
	}
	else if (dist[N - 1][M - 1][1] == 0) {
		cout << dist[N - 1][M - 1][0];
	}
	else {
		cout << min(dist[N-1][M-1][0], dist[N-1][M-1][1]);
	}

	return 0;
}