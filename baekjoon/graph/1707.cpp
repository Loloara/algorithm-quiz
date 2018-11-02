//1707 이분 그래프 https://www.acmicpc.net/problem/1707
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int color[20001];
vector<int> edges[20001];
bool ans;
void dfs(int index, int c);

int main() {
	int t, n, m, a, b, s;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		ans = true;
		for (int i = 1; i < n + 1; i++) {
			edges[i].clear();
			color[i] = 0;
		}

		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			edges[a].push_back(b);
			edges[b].push_back(a);
			s = a;
		}
		
		for (int i = 1; i < n + 1; i++) {	//왜 정점을 1부터 n까지 전부 탐색 시작점으로 사용해야 하는지 모르겠다
			if(color[i]==0)
				dfs(i, 1);
		}

		if (ans) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}

	return 0;
}

void dfs(int index, int c) {
	color[index] = c;
	for (int i = 0; i < edges[index].size(); i++) {
		if (color[edges[index][i]] == c) ans = false;
		if (color[edges[index][i]] == 0) {
			dfs(edges[index][i], 3 - c);
		}
	}
	return;
}