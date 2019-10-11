#include <iostream>
using namespace std;

int main() {
	int N, M, x, y, K, cmd, tmp;
	int arr[20][20];
	int x_dir[4] = { 0,0,-1,1 };
	int y_dir[4] = { 1,-1,0,0 };
	
	int dice[6] = { 0 };
	/*
	    0
	4	1   5
		2
		3
	*/

	cin >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];


	while(K--) {
		cin >> cmd;
		int new_x = x + x_dir[cmd - 1];
		int new_y = y + y_dir[cmd - 1];
		if (new_x < 0 || new_y < 0 || new_x >= N || new_y >= M) continue;
		x = new_x;
		y = new_y;

		switch (cmd)
		{
		case 1:	//µ¿
			tmp = dice[5];
			dice[5] = dice[3];
			dice[3] = dice[4];
			dice[4] = dice[1];
			dice[1] = tmp;
			break;
		case 2:	//¼­
			tmp = dice[4];
			dice[4] = dice[3];
			dice[3] = dice[5];
			dice[5] = dice[1];
			dice[1] = tmp;
			break;
		case 3:	//ºÏ
			tmp = dice[0];
			dice[0] = dice[3];
			dice[3] = dice[2];
			dice[2] = dice[1];
			dice[1] = tmp;
			break;
		case 4:	//³²
			tmp = dice[2];
			dice[2] = dice[3];
			dice[3] = dice[0];
			dice[0] = dice[1];
			dice[1] = tmp;
			break;
		}

		if (!arr[x][y]) {
			arr[x][y] = dice[1];
		}
		else {
			dice[1] = arr[x][y];
			arr[x][y] = 0;
		}
		cout << dice[3] << endl;
	}

	return 0;
}