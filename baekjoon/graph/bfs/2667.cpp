//2667 단지번호붙이기 https://www.acmicpc.net/problem/2667
//BFS
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ans;
queue<pair<int, int>> Q;
int nMap[25][25];
bool chk[25][25] = {};
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
void bfs(int n, int x, int y, int cnt);

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &nMap[i][j]);
		}
	}
		
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			bfs(n, x, y, 0);
		}
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}

	return 0;
}

void bfs(int n, int x, int y, int cnt) {
	if (chk[x][y] || !nMap[x][y]) return;
	Q.push(make_pair(x, y));
	chk[x][y] = true;
	cnt += 1;

	while (!Q.empty()) {
		int nodeX = Q.front().first;
		int nodeY = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int newX = nodeX + dx[i];
			int newY = nodeY + dy[i];
			if (newX < 0 || newX >= n || newY < 0 || newY >= n || chk[newX][newY] || !nMap[newX][newY]) continue;
			Q.push(make_pair(newX, newY));
			chk[newX][newY] = true;
			cnt += 1;
		}
	}
	ans.push_back(cnt);
}