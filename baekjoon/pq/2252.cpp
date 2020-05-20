#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void solution(int N, int M, vector<vector<int>> p) {
	queue<int> q;
	vector<int> gp[32001];
	int assigned[32001] = { 0 };

	for (vector<int> v : p) {
		gp[v[0]].push_back(v[1]);
		assigned[v[1]]++;
	}

	for (int i = 1; i <= N; i++) {
		if (assigned[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		cout << now << " ";
		for (int i : gp[now]) {
			if (--assigned[i] == 0) {
				q.push(i);
			}
		}
	}
	cout << endl;
}

int main() {
	int N, M, a, b;
	vector<vector<int>> priority;

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		priority.push_back(vector<int>({ a, b }));
	}

	solution(N, M, priority);

	return 0;
}