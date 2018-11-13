//2178 ¹Ì·Î Å½»ö https://www.acmicpc.net/problem/2178
//O(N)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue<pair<int, int>> Q;
int nMap[100][100];
int d[100][100];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &nMap[i][j]);
			d[i][j] = 0;
		}
	}

	Q.push(make_pair(0, 0));
	d[0][0] = 1;
	while (!Q.empty()) {
		int nodeX = Q.front().first;
		int nodeY = Q.front().second;
		int value = d[nodeX][nodeY];
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int newX = nodeX + dx[i];
			int newY = nodeY + dy[i];
			if (newX < 0 || newX >= n || newY < 0 || newY >= m) continue;
			if (d[newX][newY] || !nMap[newX][newY]) continue;
			Q.push(make_pair(newX, newY));
			d[newX][newY] = value + 1;
		}
	}

	cout << d[n - 1][m - 1];

	return 0;
}