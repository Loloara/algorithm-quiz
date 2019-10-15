#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, L;
	int board[101][101];
	int v_visited[101][101] = { 0 };
	int h_visited[101][101] = { 0 };
	int ans = 0;

	cin >> N >> L;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	bool desc;
	bool l_ans;
	for (int i = 0; i < N; i++) {
		v_visited[i][0] = 1;
		l_ans = false;
		desc = false;
		for (int j = 1; j < N; j++) {
			int diff = board[i][j] - board[i][j - 1];
			if (!diff) {
				v_visited[i][j] = v_visited[i][j - 1] + 1;
				if (desc) {
					if (L <= v_visited[i][j]) {
						v_visited[i][j] = 0;
						l_ans = true;
						desc = false;
					}
				}
			}
			else if (diff == -1) {
				if (L == 1) {
					l_ans = true;
				}
				else {
					if (desc) break;
					v_visited[i][j] = 1;
					desc = true;
				}
			}
			else if (diff == 1) {
				v_visited[i][j] = 1;
				if (desc) break;
				if (L <= v_visited[i][j - 1]) {
					l_ans = true;
				}
				else
					break;
			}
			else
				break;
			if (j == N - 1) {
				if (desc) break;
				if (l_ans || v_visited[i][j] == N) {
					ans++;
				}
			}
		}
	}

	for (int j = 0; j < N; j++) {
		h_visited[0][j] = 1;
		l_ans = false;
		desc = false;
		for (int i = 1; i < N; i++) {
			int diff = board[i][j] - board[i - 1][j];
			if (!diff) {
				h_visited[i][j] = h_visited[i - 1][j] + 1;
				if (desc) {
					if (L <= h_visited[i][j]) {
						h_visited[i][j] = 0;
						l_ans = true;
						desc = false;
					}
				}
			}
			else if (diff == -1) {
				if (L == 1) {
					l_ans = true;
				}
				else {
					if (desc) break;
					h_visited[i][j] = 1;
					desc = true;
				}
			}
			else if (diff == 1) {
				h_visited[i][j] = 1;
				if (desc) break;
				if (L <= h_visited[i - 1][j]) {
					l_ans = true;
				}
				else
					break;
			}
			else 
				break;
			if (i == N - 1) {
				if (desc) break;
				if (l_ans || h_visited[i][j] == N) {
					ans++;
				}
			}
		}
	}
	cout << ans;

	return 0;
}