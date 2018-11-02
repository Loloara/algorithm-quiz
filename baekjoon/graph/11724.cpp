//11724 연결 요소의 개수 https://www.acmicpc.net/problem/11724
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	vector<int> edges[1001];
	bool chk[1001] = {};
	queue<int> Q;
	int n, m, a, b;
	int count = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	for (int i = 1; i < n + 1; i++) {
		if (chk[i]) continue;
		count++;

		chk[i] = true;
		Q.push(i);
		while (!Q.empty()) {
			int node = Q.front();
			Q.pop();
			for (int j = 0; j < edges[node].size(); j++) {
				if (chk[edges[node][j]]) continue;
				chk[edges[node][j]] = true;
				Q.push(edges[node][j]);
			}
		}
	}

	cout << count;

	return 0;
}