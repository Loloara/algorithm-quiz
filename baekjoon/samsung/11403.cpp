#include <iostream>
#include <string.h>
using namespace std;

int N;
int gp[101][101];
bool visited[101];

/*
	n��° �ٿ��� �湮�� �� �ִ� ��� ������ üũ��
*/
void dfs(int x) {
	for (int i = 0; i < N; i++) {
		if (gp[x][i] && !visited[i]) {
			visited[i] = true;
			dfs(i);
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> gp[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		memset(visited, false, N);
		dfs(i);

		for (int j = 0; j < N; j++) {
			if (visited[j])
				gp[i][j] = 1;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << gp[i][j] << " ";
		}
		cout << endl;
	}
		

	return 0;
}