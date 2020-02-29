#include <iostream>
using namespace std;

int main() {
	int N; char move;
	int dir_x[4] = { 1,0,-1,0 };		//³²¼­ºÏµ¿
	int dir_y[4] = { 0,-1,0,1 };
	int dir = 0;
	int pos_x = 50; int pos_y = 50;
	int top_x = 50; int top_y = 50; int btm_x = 50; int btm_y = 50;
	bool board[101][101] = { false };
	board[50][50] = true;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> move;

		if (move == 'R') dir++;
		else if (move == 'L') dir--;
		else if (move == 'F') {
			pos_x += dir_x[dir];
			pos_y += dir_y[dir];
			board[pos_x][pos_y] = true;
			if (top_x < pos_x) top_x = pos_x;
			if (btm_y > pos_y) btm_y = pos_y;
			if (btm_x > pos_x) btm_x = pos_x;
			if (top_y < pos_y) top_y = pos_y;
		}
		dir = (dir + 4) % 4;
	}

	for (int i = btm_x; i <= top_x; i++) {
		for (int j = btm_y; j <= top_y; j++) {
			if (board[i][j]) cout << '.';
			else cout << '#';
		}
		if(i != top_x)
			cout << endl;
	}

	return 0;
}