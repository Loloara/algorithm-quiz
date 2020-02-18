#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool comp(const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b) {
	if (a.first < b.first) return true;
	else return false;
}

int main() {
	vector<pair<int, pair<int, int>>> cheese;
	int H, W, N, pos_x, pos_y;
	char tmp;
	bool board[1001][1001] = { false };

	cin >> H >> W >> N;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> tmp;

			board[i][j] = true;
			if (tmp == 'S') {
				pos_x = i;
				pos_y = j;
			}
			else if (tmp == 'X') {
				board[i][j] = false;
			}
			else if (tmp == '.') {
				continue;
			}
			else {
				cheese.push_back(make_pair(tmp - '0', make_pair(i, j)));
			}
		}
	}

	sort(cheese.begin(), cheese.end(), comp);

	int answer = 0;
	int dir_x[4] = { 1,-1,0,0 };
	int dir_y[4] = { 0,0,1,-1 };

	for (int i = 0; i < N; i++) {
		queue<pair<pair<int, int>, int>> q;
		bool chk[1001][1001] = { false };
		int cnt = 0;
		chk[pos_x][pos_y] = true;
		q.push(make_pair(make_pair(pos_x, pos_y), cnt));

		while (!q.empty()) {
			pos_x = q.front().first.first;
			pos_y = q.front().first.second;
			cnt = q.front().second;
			q.pop();

			if (pos_x == cheese[i].second.first && pos_y == cheese[i].second.second) {
				answer += cnt;
				break;
			}

			for (int i = 0; i < 4; i++) {
				int new_x = pos_x + dir_x[i];
				int new_y = pos_y + dir_y[i];
				if (new_x < 0 || new_y < 0 || new_x >= H || new_y >= W) continue;
				if (chk[new_x][new_y]) continue;
				if (!board[new_x][new_y]) continue;

				chk[new_x][new_y] = true;
				q.push(make_pair(make_pair(new_x, new_y), cnt + 1));
			}
		}
	}

	cout << answer;

	return 0;
}