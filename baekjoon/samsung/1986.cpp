#include <iostream>
#include <vector>
using namespace std;

int main() {
	int board[1001][1001] = { 0 };			//0 ¾ÈÀüÇÑ Ä­, 1 Äý, 2 ³ªÀÌÆ®, 3 Æù, -1 À§ÇèÇÑ Ä­
	int N, M, Q, K, P, x, y;
	vector<pair<int, int>> v_Q, v_K;

	cin >> N >> M;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> x >> y;
		v_Q.push_back(make_pair(x, y));
		board[x][y] = 1;
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> x >> y;
		v_K.push_back(make_pair(x, y));
		board[x][y] = 2;
	}
	cin >> P;
	for (int i = 0; i < P; i++) {
		cin >> x >> y;
		board[x][y] = 3;
	}

	int dir_x[8] = { 1,0,-1,0,1,1,-1,-1 };
	int dir_y[8] = { 0,1,0,-1,1,-1,1,-1 };
	for (pair<int, int> pos : v_Q) {
		for (int dir = 0; dir < 8; dir++) {
			int new_x = pos.first;
			int new_y = pos.second;
			while (true) {
				new_x += dir_x[dir];
				new_y += dir_y[dir];
				if (new_x <= 0 || new_y <= 0 || new_x > N || new_y > M) break;
				if (board[new_x][new_y] > 0) break;
				board[new_x][new_y] = -1;
			}
		}
	}

	int dir_kx[8] = { 2,2,-2,-2,1,-1,1,-1 };
	int dir_ky[8] = { 1,-1,1,-1,2,2,-2,-2 };
	for (pair<int, int> pos : v_K) {
		for (int dir = 0; dir < 8; dir++) {
			int new_x = pos.first + dir_kx[dir];
			int new_y = pos.second + dir_ky[dir];
			if (new_x <= 0 || new_y <= 0 || new_x > N || new_y > M) continue;
			if (board[new_x][new_y]) continue;
			board[new_x][new_y] = -1;
		}
	}

	int answer = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (!board[i][j]) answer++;
		}
	}

	cout << answer;

	return 0;
}