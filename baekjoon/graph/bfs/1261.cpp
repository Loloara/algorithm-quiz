//1261 ¾Ë°í½ºÆÌ https://www.acmicpc.net/problem/1261
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int main() {
	int N, M;
	int nMap[100][100];
	cin >> M >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%1d", &nMap[i][j]);

	bool chk[100][100];
	int dist[100][100];
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { -1,0,1,0 };
	queue<pair<int, int>> Q;
	queue<pair<int, int>> nextQ;
	memset(chk, false, sizeof(chk));
	memset(dist, 0, sizeof(dist));

	Q.push(make_pair(0, 0));
	chk[0][0] = true;
	dist[0][0] = 0;
	while (!Q.empty()) {
		int nodeX = Q.front().first;
		int nodeY = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int newX = nodeX + dx[i];
			int newY = nodeY + dy[i];
			if (newX<0 || newX>=N || newY<0 || newY>=M) continue;
			if (chk[newX][newY]) continue;
			chk[newX][newY] = true;
			if (nMap[newX][newY] == 1) {
				nextQ.push(make_pair(newX, newY));
				dist[newX][newY] = dist[nodeX][nodeY] + 1;
			}
			else {
				Q.push(make_pair(newX, newY));
				dist[newX][newY] = dist[nodeX][nodeY];
			}
		}

		if (Q.empty()) {
			Q = nextQ;
			nextQ = queue<pair<int, int>>();
		}
	}

	cout << dist[N - 1][M - 1];
	
	return 0;
}