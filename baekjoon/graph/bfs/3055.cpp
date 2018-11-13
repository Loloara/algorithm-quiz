//3055 ≈ª√‚ https://www.acmicpc.net/problem/3055
// O(RC)
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int main() {
	int R, C;
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { -1,0,1,0 };
	char nMap[51][51];
	char nn;
	queue<pair<int, int>> Q;
	int wDist[51][51];
	int dist[51][51];
	memset(wDist, -1, sizeof(wDist));
	memset(dist, -1, sizeof(dist));
	pair<int, int> start, target;

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		scanf("%c", &nn);
		for (int j = 0; j < C; j++) {
			scanf("%c", &nMap[i][j]);
			if (nMap[i][j] == '*') {
				Q.push(make_pair(i, j));
				wDist[i][j] = 0;
			}
			if (nMap[i][j] == 'X')
				wDist[i][j] = 0;
			if (nMap[i][j] == 'S')
				start = make_pair(i, j);
			if (nMap[i][j] == 'D')
				target = make_pair(i, j);
		}
	}

	while (!Q.empty()) {
		int nodeX = Q.front().first;
		int nodeY = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int newX = nodeX + dx[i];
			int newY = nodeY + dy[i];
			if (newX < 0 || newX >= R || newY < 0 || newY >= C) continue;
			if (wDist[newX][newY] >= 0) continue;
			if (nMap[newX][newY] == 'X' || nMap[newX][newY] == 'D') continue;
			Q.push(make_pair(newX, newY));
			wDist[newX][newY] = wDist[nodeX][nodeY] + 1;
		}
	}

	Q.push(start);
	dist[start.first][start.second] = 0;
	while (!Q.empty()) {
		int nodeX = Q.front().first;
		int nodeY = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int newX = nodeX + dx[i];
			int newY = nodeY + dy[i];
			if (newX < 0 || newX >= R || newY < 0 || newY >= C) continue;
			if (dist[newX][newY] >= 0) continue;
			if (wDist[newX][newY] != -1 && wDist[newX][newY] <= dist[nodeX][nodeY] + 1) continue;
			Q.push(make_pair(newX, newY));
			dist[newX][newY] = dist[nodeX][nodeY] + 1;
		}
	}

	if (dist[target.first][target.second] == -1)
		cout << "KAKTUS";
	else
		cout << dist[target.first][target.second];

	return 0;
}