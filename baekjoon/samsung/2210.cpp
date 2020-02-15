#include <iostream>
#include <map>
using namespace std;

int arr[5][5];
map<int, bool> isCount;
int dir_x[4] = { 1,-1,0,0 };
int dir_y[4] = { 0,0,1,-1 };
int answer = 0;

void dfs(int x, int y, int val, int depth) {
	if (depth == 6) {
		if (!isCount[val]) {
			isCount[val] = true;
			answer++;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		int new_x = x + dir_x[i];
		int new_y = y + dir_y[i];
		if (new_x < 0 || new_x>4 || new_y < 0 || new_y>4) continue;
		dfs(new_x, new_y, val * 10 + arr[new_x][new_y], depth + 1);
	}
}

int main() {	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			dfs(i, j, arr[i][j], 1);
		}
	}

	cout << answer;

	return 0;
}