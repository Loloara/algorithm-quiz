#include <iostream>
#include <vector>
using namespace std;

int N, L, R;
vector<vector<int>> board;
vector<vector<pair<int, int>>> g_con;
int pop[2001];
int index = 0;
bool visited[51][51] = { false };
bool included[51][51] = { false };
int x_dir[4] = { 0,1,0,-1 };
int y_dir[4] = { 1,0,-1,0 };

vector<pair<int,int>> dfs(int x, int y, vector<pair<int,int>> con) {
	if (visited[x][y]) return con;
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int new_x = x + x_dir[i];
		int new_y = y + y_dir[i];

		if (new_x < 0 || new_x >= N || new_y < 0 || new_y >= N) continue;
		if (included[new_x][new_y]) continue;
		int diff = abs(board[x][y] - board[new_x][new_y]);
		if (diff < L || diff > R) continue;
		
		included[new_x][new_y] = true;
		pop[index] += board[new_x][new_y];
		con.push_back(make_pair(new_x, new_y));

		con = dfs(new_x, new_y, con);
	}

	return con;
}

int main() {
	cin >> N >> L >> R;
	
	int tmp;
	for (int i = 0; i < N; i++) {
		vector<int> vTmp;
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			vTmp.push_back(tmp);
		}
		board.push_back(vTmp);
	}

	int ans = 0;
	bool keep = true;
	while (keep) {
		keep = false;
		index = 0;
		g_con.clear();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visited[i][j] = false;
				included[i][j] = false;
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				pop[index] = board[i][j];
				included[i][j] = true;
				vector<pair<int,int>> tmp = dfs(i, j, vector<pair<int,int>>());
				tmp.push_back(make_pair(i, j));

				if (tmp.size() > 1) {
					g_con.push_back(tmp);
					index++;
				}
				else
					included[i][j] = false;
			}
		}

		if (!g_con.size()) continue;
		for (int i = 0; i < g_con.size(); i++) {
			pop[i] /= g_con[i].size();
			for (int j = 0; j < g_con[i].size(); j++) {
				board[g_con[i][j].first][g_con[i][j].second] = pop[i];
			}
		}
		keep = true;
		ans++;
	}

	cout << ans;

	return 0;
}