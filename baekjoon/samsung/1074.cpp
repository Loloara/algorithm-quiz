#include <iostream>
#include <cmath>
using namespace std;

int N, r, c, answer;
int dir_x[4] = { 0,0,1,1 };
int dir_y[4] = { 0,1,0,1 };

void initData() {
	cin >> N >> r >> c;
}

void dfs(int n, pair<int, int> pos, int val) {
	if (n == 1) {
		for (int i = 0; i < 4; i++) {
			int newX = pos.first + dir_x[i];
			int newY = pos.second + dir_y[i];
			if (newX == r && newY == c) {
				answer = val + i;
				return;
			}
		}
		return;
	}
	int b = pow(2, n - 1);

	for (int i = 0; i < 4; i++) {
		int newX = pos.first + dir_x[i] * b;
		int newY = pos.second + dir_y[i] * b;

		if (newX > r || newY > c || newX + b <= r || newY + b <= c) continue;
		
		dfs(n - 1, make_pair(newX, newY), val + b * b * i);
	}
}

void solution() {
	initData();
	dfs(N, make_pair(0, 0), 0);

	cout << answer;
}

int main() {
	solution();

	return 0;
}