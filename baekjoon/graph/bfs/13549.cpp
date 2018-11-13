//13549 ¼û¹Ù²ÀÁú 3 https://www.acmicpc.net/problem/13549
//O(N)
#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	bool chk[100001] = { false };
	int dist[100001] = { 0 };
	queue<int> Q;
	queue<int> nextQ;
	
	chk[N] = true;
	Q.push(N);
	while (!Q.empty()) {
		int node = Q.front();
		Q.pop();

		if (node * 2 <= 100000) {
			if (!chk[node * 2]) {
				Q.push(node * 2);
				chk[node * 2] = true;
				dist[node * 2] = dist[node];
			}
		}
		if (node + 1 <= 100000) {
			if (!chk[node + 1]) {
				nextQ.push(node + 1);
				chk[node + 1] = true;
				dist[node + 1] = dist[node] + 1;
			}
		}
		if (node - 1 >= 0) {
			if (!chk[node - 1]) {
				nextQ.push(node - 1);
				chk[node - 1] = true;
				dist[node - 1] = dist[node] + 1;
			}
		}
		
		if (Q.empty()) {
			Q = nextQ;
			nextQ = queue<int>();
		}
	}

	cout << dist[K];

	return 0;
}