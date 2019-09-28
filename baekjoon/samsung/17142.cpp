#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> combi;
int flag[51] = { 0 };

int dirI[4] = {-1, 1, 0, 0};		//위 아래 왼 오른
int dirJ[4] = {0, 0, -1, 1};

int bfs(int N, vector<vector<int>> board, vector<pair<int, int>> actVirus) {
	int ans = 0;
	queue<pair<int, int>> q, newQ;
	int visited[51][51] = { 0 };
	vector<pair<int, int>> ee;

	for (int i = 0; i < actVirus.size(); i++)
		q.push(actVirus[i]);

	int nactV = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int newX = x + dirI[i];
			int newY = y + dirJ[i];
			if (newX >= 0 && newX < N && newY >= 0 && newY < N) {
				if (board[newX][newY] == 1) continue;
				if (board[newX][newY] == 3) continue;
				if (board[newX][newY] == 2)
					ee.push_back(make_pair(newX, newY));
				board[newX][newY] = 3;
				visited[newX][newY] = visited[x][y] + 1;
				newQ.push(make_pair(newX, newY));
			}
		}

		if (q.empty()) {
			while (!newQ.empty()) {
				q.push(newQ.front());
				newQ.pop();
			}
		}
	}
	
	for (int i = 0; i < ee.size(); i++)
		board[ee[i].first][ee[i].second] = 2;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 0)
				return -1;
			
			if (board[i][j] == 3) {
				if (ans < visited[i][j])
					ans = visited[i][j];
			}
		}
	}

	return ans;
}

int combination(int n, int r, int length)
{
	if (n == r) {
		int i;
		for (i = 0; i < n; i++) {
			flag[i] = 1;
		}
		for (i = 0; i < length; i++) {
			if (flag[i] == 1)
				combi.push_back(i);
		}
		for (i = 0; i < n; i++) {
			flag[i] = 0;
		}
		
		combi.push_back(-1);
		
		return 0;
	}
	if (r == 1) {
		int i, j;
		for (i = 0; i < n; i++) {
			flag[i] = 1;
			for (j = 0; j < length; j++) {
				if (flag[j] == 1)
					combi.push_back(j);
			}
			flag[i] = 0;
			combi.push_back(-1);
		}

		return 0;
	}
	flag[n - 1] = 1;
	combination(n - 1, r - 1, length);
	flag[n - 1] = 0;
	combination(n - 1, r, length);
}

int solution(int N, int M, vector<vector<int>> board, vector<pair<int, int>> virus) {
	int ans = 2000000000;

	for (int i = 0; i < N; i++)
		flag[i] = 0;
	combination(virus.size(), M, virus.size());

	vector<vector<int>> comb;
	vector<int> vTmp;
	for (int i = 0; i < combi.size(); i++) {
		if (combi[i] == -1) {
			comb.push_back(vTmp);
			vTmp.clear();
			continue;
		}
		vTmp.push_back(combi[i]);
	}

	for (int i = 0; i < comb.size(); i++) {
		vector<vector<int>> newBoard(board);
		vector<pair<int, int>> actVirus;
		for (int j = 0; j < M; j++) {
			newBoard[virus[comb[i][j]].first][virus[comb[i][j]].second] = 3;
			actVirus.push_back(make_pair(virus[comb[i][j]].first, virus[comb[i][j]].second));
		}

		int tmp = bfs(N, newBoard, actVirus);
		if (tmp == -1) continue;
		if (ans > tmp)
			ans = tmp;
	}

	if (ans == 2000000000) return -1;

	return ans;
}


int main() {
	int N, M;
	vector<vector<int>> board;
	vector<pair<int, int>> virus;
	int tmp;
	int vMax = 0;
	
	cin >> N >> M;


	for (int i = 0; i < N; i++) {
		vector<int> vTmp;
		for (int j = 0; j < N; j++) {
			cin >> tmp;

			if (!tmp) vMax++;

			if (tmp == 2)
				virus.push_back(make_pair(i, j));
			vTmp.push_back(tmp);
		}
		board.push_back(vTmp);
	}

	if (!vMax)
		cout << 0;

	cout << solution(N, M, board, virus);

	return 0;
}