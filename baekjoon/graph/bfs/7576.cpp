//7576 토마토 https://www.acmicpc.net/problem/7576
//O(NM)
#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, m;
	int nMap[1000][1000];
	int d[1000][1000];
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { -1,0,1,0 };
	queue<pair<int, int>> Q;

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> nMap[i][j];
			d[i][j] = 0;
			if (nMap[i][j] == 1) {		//여기가 핵심 시작 지점을 전부 큐에 미리 넣어 같은 레벨에서 시작한다.
				Q.push(make_pair(i, j));
				d[i][j] = 1;
			}
		}
	}

	while (!Q.empty()) {
		int nodeX = Q.front().first;
		int nodeY = Q.front().second;
		Q.pop();

		for (int k = 0; k < 4; k++) {
			int newX = nodeX + dx[k];
			int newY = nodeY + dy[k];
			if (newX < 0 || newX >= n || newY < 0 || newY >= m) continue;
			if (nMap[newX][newY] || d[newX][newY]) continue;
			Q.push(make_pair(newX, newY));
			d[newX][newY] = d[nodeX][nodeY] + 1;
		}
	}

	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (max < d[i][j]) max = d[i][j];
			if (!d[i][j] && (nMap[i][j] != -1)) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << max-1;

	return 0;
}