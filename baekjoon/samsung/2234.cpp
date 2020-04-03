#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, roomNum, MAX, twoRooms;
int board[50][50];
int visited[50][50];
vector<int> roomList;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int chkWall[4] = { 8,4,2,1 };

void initData() {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	roomList.push_back(0);
}

int bfs(int x, int y) {
	int rs = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visited[x][y] = roomNum;

	while(!q.empty()) {
		pair<int,int> now = q.front();
		int wall = board[now.first][now.second];
		q.pop();
		rs++;
		
		for (int i = 0; i < 4; i++) {
			int newX = now.first + dx[i];
			int newY = now.second + dy[i];
			wall -= chkWall[i];
			if (wall >= 0) continue;
			else wall += chkWall[i];
			if (visited[newX][newY]) continue;
			visited[newX][newY] = roomNum;
			q.push(make_pair(newX, newY));
		}
	}

	return rs;
}

void solution() {
	initData();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) if (!visited[i][j]) {
			roomNum++;
			int roomSize = bfs(i, j);
			roomList.push_back(roomSize);
			if (MAX < roomSize) {
				MAX = roomSize;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (j + 1 < M) {
				if (visited[i][j] != visited[i][j + 1]) {
					int two = roomList[visited[i][j]] + roomList[visited[i][j + 1]];
					if (twoRooms < two) {
						twoRooms = two;
					}
				}
			}
			if (i + 1 < N) {
				if (visited[i][j] != visited[i + 1][j]) {
					int two = roomList[visited[i][j]] + roomList[visited[i + 1][j]];
					if (twoRooms < two) {
						twoRooms = two;
					}
				}
			}
		}
	}

	cout << roomNum << endl;
	cout << MAX << endl;
	cout << twoRooms;
}

int main() {
	solution();

	return 0;
}