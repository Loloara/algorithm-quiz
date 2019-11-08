#include <iostream>
#include <deque>
using namespace std;

struct horse {
	int x, y, dir;
	horse(int a, int b, int c) : x(a), y(b), dir(c) {};
};

int main() {
	int board[13][13];
	horse* hp[11];
	deque<int> chess[13][13];
	int N, K;
	int dx[5] = { 0,0,0,-1,1 };
	int dy[5] = { 0,1,-1,0,0 };
	
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> board[i][j];

	int x, y, dir;
	for (int i = 1; i <= K; i++) {
		cin >> x >> y >> dir;
		hp[i] = new horse(x, y, dir);
		chess[x][y].push_back(i);
	}

	int turn = 0;
	bool next = true;
	while (turn <= 1000 && next) {
		turn++;
		int new_x = 0, new_y = 0;

		for (int i = 1; i <= K; i++) {
			x = hp[i]->x;
			y = hp[i]->y;
			new_x = x + dx[hp[i]->dir];
			new_y = y + dy[hp[i]->dir];
			if (new_x > N || new_x < 1 || new_y > N || new_y < 1) {
				if (hp[i]->dir % 2) hp[i]->dir += 1;
				else hp[i]->dir -= 1;
				new_x = x + dx[hp[i]->dir];
				new_y = y + dy[hp[i]->dir];
				if (board[new_x][new_y] == 2) continue;
			}
			if (board[new_x][new_y] == 2) {
				if (hp[i]->dir % 2) hp[i]->dir += 1;
				else hp[i]->dir -= 1;
				new_x = x + dx[hp[i]->dir];
				new_y = y + dy[hp[i]->dir];
				if (new_x > N || new_x < 1 || new_y > N || new_y < 1) continue;
				if (board[new_x][new_y] == 2) continue;
			}
			
			if (board[new_x][new_y] == 0) { //Èò»ö
				int count = 0;
				bool keep = true;
				for (int j = 0; j < chess[x][y].size(); j++) {
					if (chess[x][y][j] == i) keep = false;
					if (keep) continue;
					chess[new_x][new_y].push_back(chess[x][y][j]);
					hp[chess[x][y][j]]->x = new_x;
					hp[chess[x][y][j]]->y = new_y;
					count++;
				}
				for (int j = 0; j < count; j++)
					chess[x][y].pop_back();
			}
			else if (board[new_x][new_y] == 1) { //»¡°£»ö
				int count = 0;
				for (int j = chess[x][y].size() - 1; j >= 0; j--) {
					chess[new_x][new_y].push_back(chess[x][y][j]);
					hp[chess[x][y][j]]->x = new_x;
					hp[chess[x][y][j]]->y = new_y;
					count++;
					if (chess[x][y][j] == i) break;
				}
				for (int j = 0; j < count; j++)
					chess[x][y].pop_back();
			}

			if (chess[new_x][new_y].size() >= 4) {
				next = false;
				break;
			}
		}
	}

	if (turn > 1000)
		cout << -1;
	else
		cout << turn;

	return 0;
}