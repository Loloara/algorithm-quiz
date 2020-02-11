#include <iostream>
using namespace std;

int main() {
	int N, M;
	int arr[1001][1001];
	int mem[1001][1001];

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
			
			int up = 0; int left = 0;
			if (i - 1 > 0) up = mem[i - 1][j];
			if (j - 1 > 0) left = mem[i][j - 1];

			mem[i][j] = (up > left ? up : left) + arr[i][j];
		}
	}

	cout << mem[N][M];

	return 0;
}