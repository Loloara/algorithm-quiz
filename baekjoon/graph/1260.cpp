//1260 DFS¿Í BFS https://www.acmicpc.net/problem/1260
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> edges[1001];
queue<int> Q;
bool chk[1001] = {};
void dfs(int index);
void bfs(int index);

int main() {
	int n, m, s, a, b;
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	for (int i = 1; i < n + 1; i++)
		sort(edges[i].begin(), edges[i].end());

	dfs(s);
	cout << '\n';
	for (int i = 0; i < n+1; i++)
		chk[i] = false;

	bfs(s);

	return 0;
}

void dfs(int index) {
	chk[index] = true;
	cout << index << ' ';
	for (int i = 0; i < edges[index].size(); i++) {
		if (chk[edges[index][i]] == false) {
			dfs(edges[index][i]);
		}
	}

}

void bfs(int index) {
	Q.push(index);
	chk[index] = true;
	while (!Q.empty()) {
		int node = Q.front(); Q.pop();
		cout << node << ' ';

		for (int i = 0; i < edges[node].size(); i++) {
			if (chk[edges[node][i]]) continue;
			chk[edges[node][i]] = true;
			Q.push(edges[node][i]);
		}
	}
}