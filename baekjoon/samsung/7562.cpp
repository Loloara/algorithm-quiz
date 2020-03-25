#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int dir_x[8] = { -2,-2,-1,-1,1,1,2,2 };
int dir_y[8] = { -1,1,-2,2,-2,2,-1,1 };
bool visited[300][300];
int T, I, answer;
pair<int, int> pos, target;
struct node {
	pair<int, int> pos;
	int depth;
	node(pair<int, int> p, int d) : pos(p), depth(d) {}
};

void initData() {
	cin >> I;
	cin >> pos.first >> pos.second;
	cin >> target.first >> target.second;
	for (int i = 0; i < I; i++) {
		memset(visited[i], false, sizeof(bool) * I);
	}
	answer = -1;
}

void bfs() {
	queue<node> q;
	q.push(node(make_pair(pos.first,pos.second),0));
	while (!q.empty()) {
		node currentNode = q.front();
		q.pop();
		if (currentNode.pos.first == target.first && currentNode.pos.second == target.second) {
			answer = currentNode.depth;
			break;
		}

		for (int i = 0; i < 8; i++) {
			int newX = currentNode.pos.first + dir_x[i];
			int newY = currentNode.pos.second + dir_y[i];
			if (newX < 0 || newY < 0 || newX >= I || newY >= I) continue;
			if (visited[newX][newY]) continue;
			visited[newX][newY] = true;
			q.push(node(make_pair(newX, newY), currentNode.depth + 1));
		}
	}
}

void printAnswer() {
	if (answer != -1) {
		cout << answer << endl;
	}
	else {
		cout << "no answer" << endl;
	}
}

void solution() {
	initData();
	bfs();
	printAnswer();
}

int main() {
	cin >> T;
	while (T--) {
		solution();
	}

	return 0;
}