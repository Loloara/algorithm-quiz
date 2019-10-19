#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N, K;
	int chk[100002] = { 0 };
	bool visited[100002] = { false };

	cin >> N >> K;

	if (N == K) {
		cout << 0;
		return 0;
	}

	queue<int> q, nextq;
	q.push(N);
	int count = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		int a1 = x + 1;
		int a2 = x - 1;
		int a3 = x * 2;
		if (a3 <= 100000) {
			if (chk[x] < chk[a3] || !visited[a3]) {
				chk[a3] = chk[x];
				visited[a3] = true;
				q.push(a3);
			}
		}
		if (a1 <= 100000) {
			if (!visited[a1] || chk[a1] > chk[x] + 1) {
				chk[a1] = chk[x] + 1;
				visited[a1] = true;
				q.push(a1);
			}
		}
		if (a2 >= 0) {
			if (!visited[a2] || chk[a2] > chk[x] + 1) {
				chk[a2] = chk[x] + 1;
				visited[a2] = true;
				q.push(a2);
			}
		}
	}

	cout << chk[K];

	return 0;
}