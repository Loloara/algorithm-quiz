#include <iostream>
#include <vector>
using namespace std;

int board[101][101] = { 0 };
bool dragon[101][101] = { false };

int main() {
	int N, board_size = 0;
	cin >> N;


	int x, y, d, g, depth;
	vector<pair<int, int>> va;
	for (int i = 0; i < N; i++) {
		va.clear();
		cin >> x >> y >> d >> g;
		dragon[y][x] = true;
		va.push_back(make_pair(y, x));
		if (x > board_size) board_size = x;
		if (y > board_size) board_size = y;
		switch (d) {
		case 0:
			x += 1;
			if (x > board_size) board_size = x;
			break;
		case 1:
			y -= 1;
			break;
		case 2:
			x -= 1;
			break;
		case 3:
			y += 1;
			if (y > board_size) board_size = y;
			break;
		}
		va.push_back(make_pair(y, x));
		dragon[y][x] = true;

		for (int i = 0; i < g; i++) {
			int diff_x = x - ((-1) * (y - va[0].first) + va[0].second);
			int diff_y = y - ((x - va[0].second) + va[0].first);

			int loop = va.size() - 2;
			for (int i = loop; i >= 0; i--) {
				int new_x = ((-1) * (va[i].first-va[0].first) + va[0].second) + diff_x;
				int new_y = (va[i].second - va[0].second) + va[0].first + diff_y;
				dragon[new_y][new_x] = true;
				va.push_back(make_pair(new_y, new_x));

				if (new_x > board_size) board_size = new_x;
				if (new_y > board_size) board_size = new_y;

				if (i == 0) {
					x = new_x;
					y = new_y;
				}
			}
		}
	}

	//정사각형 갯수 찾기
	int ans = 0;
	for (int i = 0; i <= board_size; i++) {
		for (int j = 0; j <= board_size; j++) {
			if (dragon[i][j] && dragon[i + 1][j] && dragon[i][j + 1] && dragon[i + 1][j + 1])
				ans++;
		}
	}
	cout << ans;

	return 0;
}