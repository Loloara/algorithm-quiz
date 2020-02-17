#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int M, N, K;
bool arr[101][101];
vector<int> scope_size;
int answer = 0;
int x_dir[4] = { 1,-1,0,0 };
int y_dir[4] = { 0,0,1,-1 };

int dfs(int x, int y, int cnt) {
	arr[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int new_x = x + x_dir[i];
		int new_y = y + y_dir[i];
		if (new_x < 0 || new_y < 0 || new_x >= N || new_y >= M) continue;
		if (arr[new_x][new_y]) continue;
		cnt += dfs(new_x, new_y, 1);
	}

	return cnt;
}

int main() {
	cin >> M >> N >> K;

	for (int t = 0; t < K; t++) {
		int i_begin, i_end, j_begin, j_end;
		cin >> i_begin >> j_begin >> i_end >> j_end;
		for (int i = i_begin; i < i_end; i++) {
			for (int j = j_begin; j < j_end; j++) {
				arr[i][j] = true;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j]) continue;
			answer++;
			scope_size.push_back(dfs(i, j, 1));
		}
	}

	sort(scope_size.begin(), scope_size.end());

	cout << answer << endl;
	for (int x : scope_size)
		cout << x << " ";
	

	return 0;
}