#include <iostream>
#include <string.h>
using namespace std;

int F, S, G, U, D;
int visited[1000001];

void initData() {
	cin >> F >> S >> G >> U >> D;
	memset(visited, -1, sizeof(int) * (F + 1));
}

void dp(int index, int depth) {
	if (visited[index] != -1 && depth >= visited[index]) return;
	visited[index] = depth;
	if (index == G) return;
	if (index + U <= F) dp(index + U, depth + 1);
	if (index - D >= 1) dp(index - D, depth + 1);
}

void printAnswer() {
	if (visited[G] != -1) cout << visited[G];
	else cout << "use the stairs";
}

void solution() {
	initData();
	dp(S, 0);
	printAnswer();
}

int main() {
	solution();

	return 0;
}