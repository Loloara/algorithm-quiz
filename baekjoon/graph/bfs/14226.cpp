//14226 이모티콘 https://www.acmicpc.net/problem/14226
//O(N)
#include <iostream>
#include <queue>
#include <cstring>	//memset
using namespace std;

int main() {
	int S; // 2~1000
	cin >> S;

	queue<pair<int, int>> Q;
	int dist[1001][1001];
	memset(dist, -1, sizeof(dist));

	Q.push(make_pair(1, 0));
	dist[1][0] = 0;

	while (!Q.empty()) {
		int s = Q.front().first;
		int c = Q.front().second;
		Q.pop();

		int nextS = s;
		int nextC = s;
		if (dist[nextS][nextC] == -1) {
			Q.push(make_pair(nextS, nextC));
			dist[nextS][nextC] = dist[s][c] + 1;
		}

		nextS = s + c;
		nextC = c;
		if (nextS <= 1000 && dist[nextS][nextC] == -1) {
			Q.push(make_pair(nextS, nextC));
			dist[nextS][nextC] = dist[s][c] + 1;
		}

		nextS = s - 1;
		nextC = c;
		if (nextS >= 0 && dist[nextS][nextC] == -1) {
			Q.push(make_pair(nextS, nextC));
			dist[nextS][nextC] = dist[s][c] + 1;
		}
	}

	int ans = 1000000000;
	for (int i = 0; i <= 1000; i++) {
		if (dist[S][i] == -1) continue;
		if (ans > dist[S][i]) ans = dist[S][i];
	}
	cout << ans;

	return 0;
}