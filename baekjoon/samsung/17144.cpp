#include <iostream>
#include <vector>
using namespace std;

int solution(int R, int C, int T, vector<vector<int>> Arc) {
	int spread[50][50] = { 0 };
	int a1, a2;
	for (int i = 0; i < R; i++) {
		if (Arc[i][0] == -1) {
			a1 = i;
			a2 = i + 1;
			break;
		}
	}


	for (int t = 0; t < T; t++) {
		for (int i = 0; i < R; i++) {	//확산
			for (int j = 0; j < C; j++) {
				if (Arc[i][j] < 5) continue;
				int spreadPoint = Arc[i][j] / 5;
				int spreadCount = 0;

				if (i > 0) {
					if (Arc[i - 1][j] != -1) {
						spread[i - 1][j] += spreadPoint;
						spreadCount++;
					}
				}

				if (i < R - 1) {
					if (Arc[i + 1][j] != -1) {
						spread[i + 1][j] += spreadPoint;
						spreadCount++;
					}
				}

				if (j > 0) {
					if (Arc[i][j - 1] != -1) {
						spread[i][j - 1] += spreadPoint;
						spreadCount++;
					}
				}

				if (j < C - 1) {
					if (Arc[i][j + 1] != -1) {
						spread[i][j + 1] += spreadPoint;
						spreadCount++;
					}
				}
				Arc[i][j] = Arc[i][j] - (spreadPoint * spreadCount);
			}
		}

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				Arc[i][j] += spread[i][j];
				spread[i][j] = 0;
			}
		}

		int last1 = 0;
		int last2 = 0;
		for (int j = 1; j < C; j++) {	//공기청정기 좌->우
			int tmp1 = Arc[a1][j];
			int tmp2 = Arc[a2][j];
			Arc[a1][j] = last1;
			Arc[a2][j] = last2;
			last1 = tmp1;
			last2 = tmp2;
		}

		for (int i = a1 - 1; i >= 0; i--) { //하->상
			int tmp1 = Arc[i][C - 1];
			Arc[i][C - 1] = last1;
			last1 = tmp1;
		}

		for (int i = a2 + 1; i < R; i++) { //상 ->하
			int tmp2 = Arc[i][C - 1];
			Arc[i][C - 1] = last2;
			last2 = tmp2;
		}

		for (int j = C - 2; j >= 0; j--) { //우->좌
			int tmp1 = Arc[0][j];
			int tmp2 = Arc[R - 1][j];
			Arc[0][j] = last1;
			Arc[R - 1][j] = last2;
			last1 = tmp1;
			last2 = tmp2;
		}

		for (int i = 1; i < a1; i++) { //상->하
			int tmp1 = Arc[i][0];
			Arc[i][0] = last1;
			last1 = tmp1;
		}

		for (int i = R - 2; i > a2; i--) {	//하->상
			int tmp2 = Arc[i][0];
			Arc[i][0] = last2;
			last2 = tmp2;
		}
	}

	int answer = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (Arc[i][j] == -1) continue;
			answer += Arc[i][j];
		}
	}

	return answer;
}

int main() {
	int R, C, T;
	vector<vector<int>> Arc;

	cin >> R >> C >> T;
	for (int i = 0; i < R; i++) {
		vector<int> vTmp;
		int tmp;
		for (int j = 0; j < C; j++) {
			cin >> tmp;
			vTmp.push_back(tmp);
		}
		Arc.push_back(vTmp);
	}
	cout << solution(R, C, T, Arc);

	return 0;
}