#include <iostream>
using namespace std;

int R, C, o, v;
char m_arr[250][250];
bool visited[250][250];
int dir_x[4] = { 1, -1, 0, 0 };
int dir_y[4] = { 0, 0, 1, -1 };

void dfs(int a, int b) {
	if (a >= R || b >= C || a < 0 || b < 0) return;
	if (visited[a][b]) return;
	if (m_arr[a][b] == '#') return;

	visited[a][b] = true;
	if (m_arr[a][b] == 'o') o++;
	else if (m_arr[a][b] == 'v') v++;

	for (int i = 0; i < 4; i++) {
		dfs(a + dir_x[i], b + dir_y[i]);
	}
}

int main() {
	int total_o = 0;
	int total_v = 0;

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> m_arr[i][j];
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (visited[i][j] || m_arr[i][j] == '#') continue;
			o = 0;
			v = 0;
			dfs(i, j);
			if (o > v) {
				total_o += o;
			}
			else {
				total_v += v;
			}
		}
	}

	cout << total_o << " " << total_v;


	return 0;
}