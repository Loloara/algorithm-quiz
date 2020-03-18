#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct Bottles {
	int A, B, C;
	Bottles(int a, int b, int c) : A(a), B(b), C(c) {}
};

int main() {
	priority_queue<int, vector<int>, greater<int>> pq;
	queue<Bottles> q;
	map<int,bool> visited;
	map<int,bool> dup;
	int volums[3];

	cin >> volums[0] >> volums[1] >> volums[2];
	Bottles bottles(0, 0, volums[2]);

	pq.push(bottles.C);
	q.push(bottles);
	visited[bottles.C] = true;
	dup[bottles.C] = true;

	while (!q.empty()) {
		Bottles bottle = q.front();
		q.pop();

		for (int from = 0; from < 3; from++) {
			for (int to = 0; to < 3; to++) {
				int bottles[3] = { bottle.A, bottle.B, bottle.C };
				if (!bottles[from]) break;
				if (to != from) {
					int remainOfTo = volums[to] - bottles[to];
					if (bottles[from] > remainOfTo) {
						bottles[from] -= remainOfTo;
						bottles[to] = volums[to];
					}
					else {
						bottles[to] += bottles[from];
						bottles[from] = 0;
					}
					if (!bottles[0] && !dup[bottles[2]]) {
						pq.push(bottles[2]);
						dup[bottles[2]] = true;
					}
					int vst = bottles[0] * 1000000 + bottles[1] * 1000 + bottles[0];
					if (visited[vst]) continue;
					visited[vst] = true;
					q.push(Bottles(bottles[0], bottles[1], bottles[2]));
				}
			}
		}
	}

	cout << pq.top();
	pq.pop();
	while (!pq.empty()) {
		cout << " " << pq.top();
		pq.pop();
	}

	return 0;
}