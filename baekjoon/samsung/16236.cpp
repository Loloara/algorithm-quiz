#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool comp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.first == b.first) return (a.second < b.second);
	else return (a.first < b.first);
}

int main() {
	int x_dir[4] = { 0,-1,0,1 };
	int y_dir[4] = { 1,0,-1,0 };
	int shark = 2;
	int eat_count = 0;
	int board[21][21] = { 0 };
	int x, y;

	vector<pair<int, int>> eat;
	queue<pair<int, int>> q;
	int N;
	int time_index = 0;

	cin >> N;
	int tmp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			if (tmp == 9) {
				x = i;
				y = j;
			}

			board[i][j] = tmp;
		}
	}

	while (true) {
		int mem[21][21] = { 0 };
		int distance = 0;
		eat.clear();

		q.push(make_pair(x, y));

		while (!q.empty()) {
			int this_x = q.front().first;
			int this_y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int new_x = this_x + x_dir[i];
				int new_y = this_y + y_dir[i];
				if (new_x < 0 || new_x >= N || new_y < 0 || new_y >= N) continue;
				if (board[new_x][new_y] > shark) continue;
				if (mem[new_x][new_y] && (mem[new_x][new_y] <= mem[this_x][this_y] + 1)) continue;
				else mem[new_x][new_y] = mem[this_x][this_y] + 1;
				if (board[new_x][new_y] > 0 && board[new_x][new_y] < shark) {	//여기 때문에 샤크 사이즈 9보다 커지면 무한루프
					if (eat.empty() || (!eat.empty() && mem[eat[0].first][eat[0].second] == mem[new_x][new_y])) {
						eat.push_back(make_pair(new_x, new_y));
						distance = mem[new_x][new_y];
					}
					else break;
				}
				q.push(make_pair(new_x, new_y));
			}
		}

		if (!distance) {
			cout << time_index;
			break;
		}

		if (eat.size() > 1)
			sort(eat.begin(), eat.end(), comp);

		time_index += distance;
		board[x][y] = 0;
		x = eat[0].first;
		y = eat[0].second;
		board[x][y] = 9;
		
		if (shark == 7) continue;		//샤크 사이즈 9이상 되면 미침
		if (++eat_count == shark) {
			shark++;
			eat_count = 0;
		}
	}

	return 0;
}