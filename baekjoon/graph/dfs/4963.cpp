//4963 ¼¶ÀÇ °³¼ö https://www.acmicpc.net/problem/4963
//dfs
#include <iostream>
#include <vector>
using namespace std;

int nMap[50][50];
bool chk[50][50];
bool ok;
int dx[8] = { 0,1,0,-1,1,1,-1,-1 };
int dy[8] = { -1,0,1,0,-1,1,1,-1 };
int ans;
void dfs(int x, int y, int w, int h);

int main() {
	while (true) {
		int w, h, num;
		cin >> h >> w;
		if (!w && !h) break;

		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				cin >> nMap[i][j];
				chk[i][j] = false;
			}
		}
		
		ans = 0;

		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				ok = false;
				dfs(i, j, w, h);
				if (ok) ans += 1;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}

void dfs(int x, int y, int w, int h) {
	if (x < 0 || x >= w || y < 0 || y >= h) return;
	if (chk[x][y] || !nMap[x][y]) return;
	ok = true;
	chk[x][y] = true;
	for (int i = 0; i < 8; i++) {
		int newX = x + dx[i];
		int newY = y + dy[i];
		if (newX < 0 || newX >= w || newY < 0 || newY >= h) continue;
		if(chk[newX][newY] || !nMap[newX][newY]) continue;
		dfs(newX, newY, w, h);
	}
}