#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> board;
vector<pair<int, int>> shop;
vector<pair<int, int>> house;
bool visited[14] = { false };
int min_v = INT16_MAX;

void dfs(int index, vector<vector<int>> board, int depth) {
	if (depth == M) {
		int ans = 0;
		for (int i = 0; i < house.size(); i++) {
			int diff = 999999;
			for (int j = 0; j < shop.size(); j++) {
				if (!visited[j]) continue;
				int tmp = abs(house[i].first - shop[j].first) + abs(house[i].second - shop[j].second);
				diff = tmp < diff ? tmp : diff;
			}
			ans += diff;
		}

		min_v = min_v < ans ? min_v : ans;

		return;
	}
	if (index == shop.size() - 1) return;
	

	for (int i = index + 1; i < shop.size(); i++) {
		if (M - depth > shop.size() - i) continue;
		visited[i] = true;
		dfs(i, board, depth + 1);
		visited[i] = false;
	}
}

int main() {
	cin >> N >> M;

	int tmp;
	for (int i = 0; i < N; i++) {
		vector<int> vTmp;
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			vTmp.push_back(tmp);
			if (tmp == 2) shop.push_back(make_pair(i, j));
			if (tmp == 1) house.push_back(make_pair(i, j));
		}
		board.push_back(vTmp);
	}

	dfs(-1, board, 0);

	cout << min_v;

	return 0;
}