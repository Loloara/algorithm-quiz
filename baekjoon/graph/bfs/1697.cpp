//1697 ¼û¹Ù²ÀÁú https://www.acmicpc.net/problem/1697
// O(N)
#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	queue<int> Q;
	bool chk[100001] = {};
	int dist[100001] = { 0 };
	Q.push(N);
	chk[N] = true;

	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		
		int next = now + 1;
		if (next >= 0 && next <= 100000) {
			if (!chk[next]) {
				Q.push(next);
				chk[next] = true;
				dist[next] = dist[now] + 1;
			}
		}

		next = now - 1;
		if (next >= 0 && next <= 100000) {
			if (!chk[next]) {
				Q.push(next);
				chk[next] = true;
				dist[next] = dist[now] + 1;
			}
		}

		next = now * 2;
		if (next >= 0 && next <= 100000) {
			if (!chk[next]) {
				Q.push(next);
				chk[next] = true;
				dist[next] = dist[now] + 1;
			}
		}
	}

	cout << dist[K];

	return 0;
}