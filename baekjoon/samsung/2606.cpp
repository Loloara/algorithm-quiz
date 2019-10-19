#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int N, M;
	vector<int> net[101];
	cin >> N >> M;
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		net[a].push_back(b);
		net[b].push_back(a);
	}

	int ans = 0;
	bool visited[101] = { false };
	int next = 1;
	queue<int> q;
	q.push(next);
	visited[next] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < net[x].size(); i++) {
			if (visited[net[x][i]]) continue;
			ans++;
			visited[net[x][i]] = true;
			q.push(net[x][i]);
		}
	}

	cout << ans;

	return 0;
}