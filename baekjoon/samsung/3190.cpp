#include <iostream>
#include <deque>
using namespace std;

int main() {
	int N, K, L;
	int board[101][101] = { 0 };
	int time_index = 0;
	int x_dir[4] = { 0,1,0,-1 };	//오른쪽, 아래쪽, 왼쪽, 위쪽
	int y_dir[4] = { 1,0,-1,0 };
	int dir_index = 0;
	deque<pair<int, int>> snake;
	deque<pair<int, char>> change_dir;
	snake.push_back(make_pair(1, 1));
	
	cin >> N >> K;

	int x, y;
	for (int i = 1; i <= K; i++) {
		cin >> x >> y;
		board[x][y] = 1;
	}
	board[1][1] = 2;

	cin >> L;

	char d;
	for (int i = 0; i < L; i++) {
		cin >> x >> d;
		change_dir.push_back(make_pair(x, d));
	}

	while (true) {
		time_index++;
		x = snake.back().first;
		y = snake.back().second;

		int new_x = x + x_dir[dir_index];
		int new_y = y + y_dir[dir_index];

		if (new_x <= 0 || new_x > N || new_y <= 0 || new_y > N) {
			cout << time_index;
			break;
		}
		if (board[new_x][new_y] == 2) {
			cout << time_index;
			break;
		}
		if (board[new_x][new_y] == 0) {
			x = snake.front().first;
			y = snake.front().second;
			snake.pop_front();
			board[x][y] = 0;
		}

		snake.push_back(make_pair(new_x, new_y));
		board[new_x][new_y] = 2;

		if (change_dir.empty()) continue;
		if (time_index == change_dir.front().first) {
			if (change_dir.front().second == 'L')	//왼쪽
				dir_index--;
			else									//오른쪽
				dir_index++;
			dir_index += 4;
			dir_index %= 4;
			change_dir.pop_front();
		}
	}

	return 0;
}