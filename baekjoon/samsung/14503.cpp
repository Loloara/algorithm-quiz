#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, M, dir;
	int x, y;
	int board[51][51];
	int x_dir[4] = { -1,0,1,0 };
	int y_dir[4] = { 0,1,0,-1 };

	cin >> N >> M;
	cin >> x >> y >> dir;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];

	int ans = 0;
	while (board[x][y] != 1) {
		if (!board[x][y]) {		//1번
			ans++;
			board[x][y] = 2;
		}

		bool keep = false;
		for (int i = 0; i < 4; i++) {	//2번
			dir = (dir - 1 + 4) % 4;
			int new_x = x + x_dir[dir];
			int new_y = y + y_dir[dir];
			
			if (!board[new_x][new_y]) {	//2-a 번
				x = new_x;
				y = new_y;
				keep = true;
				break;
			}
		}
		if (keep) continue;	//2-a번
		int back_dir = (dir + 2) % 4;
		x = x + x_dir[back_dir];
		y = y + y_dir[back_dir];
	}



	cout << ans;

	return 0;
}