#include <iostream>
#include <deque>
using namespace std;

int x_dir[8] = { 0,0,1,-1,-1,-1,1,1 };
int y_dir[8] = { 1,-1,0,0,1,-1,1,-1 };

int main() {
	int N, M, K;
	int A[11][11];
	int F[11][11];
	deque<int> B[11][11];

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> F[i][j];
			A[i][j] = 5;
		}
	}

	int x, y, z;
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> z;
		B[x][y].push_back(z);
	}

	for (int i = 0; i < K; i++) {
		//봄
		for (int j = 1; j <= N; j++) {
			for (int h = 1; h <= N; h++) {
				int dead_count = 0;
				int dead = 0;
				for (int k = 0; k < B[j][h].size(); k++) {
					if (A[j][h] >= B[j][h][k]) {
						A[j][h] -= B[j][h][k];
						B[j][h][k]++;
					}
					else {
						dead += B[j][h][k] / 2;
						dead_count++;
					}
				}
				A[j][h] += dead; //여름
				while (dead_count--) {
					B[j][h].pop_back();
				}
			}
		}

		//가을
		for (int j = 1; j <= N; j++) {
			for (int h = 1; h <= N; h++) {
				for (int k = 0; k < B[j][h].size();k++) {
					if (!(B[j][h][k] % 5)) {
						for (int d = 0; d < 8; d++) {
							int new_x = j + x_dir[d];
							int new_y = h + y_dir[d];
							if (new_x < 1 || new_y < 1 || new_x > N || new_y > N) continue;
							B[new_x][new_y].push_front(1);
						}
					}
				}
			}
		}

		//겨울
		for (int j = 1; j <= N; j++)
			for (int h = 1; h <= N; h++)
				A[j][h] += F[j][h];
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			ans += B[i][j].size();
		}
	}

	cout << ans;

	return 0;
}