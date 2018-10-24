//14500 테트로미노 https://www.acmicpc.net/problem/14500
#include <iostream>
using namespace std;

int main() {
	int chkCase[19][3][2] = {	//블록들을 대칭 및 회전시켜 19개의 모양을 행렬로 표시한다.
	{{0,1}, {0,2}, {0,3}},
	{{1,0}, {2,0}, {3,0}},
	{{1,0}, {1,1}, {1,2}},
	{{0,1}, {1,0}, {2,0}},
	{{0,1}, {0,2}, {1,2}},
	{{1,0}, {2,0}, {2,-1}},
	{{0,1}, {0,2}, {-1,2}},
	{{1,0}, {2,0}, {2,1}},
	{{0,1}, {0,2}, {1,0}},
	{{0,1}, {1,1}, {2,1}},
	{{0,1}, {1,0}, {1,1}},
	{{0,1}, {-1,1}, {-1,2}},
	{{1,0}, {1,1}, {2,1}},
	{{0,1}, {1,1}, {1,2}},
	{{1,0}, {1,-1}, {2,-1}},
	{{0,1}, {0,2}, {-1,1}},
	{{0,1}, {0,2}, {1,1}},
	{{1,0}, {2,0}, {1,1}},
	{{1,0}, {2,0}, {1,-1}},
	};
	int nMap[501][501] = {};
	int N, M;
	int MAX = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> nMap[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 19; k++) {
				if (i + chkCase[k][0][0] < 0 || i + chkCase[k][1][0] < 0 || i + chkCase[k][2][0] < 0 ||
					j + chkCase[k][0][1] < 0 || j + chkCase[k][1][1] < 0 || j + chkCase[k][2][1] < 0 ||
					i + chkCase[k][0][0] >= N || i + chkCase[k][1][0] >= N || i + chkCase[k][2][0] >= N ||
					j + chkCase[k][0][1] >= M || j + chkCase[k][1][1] >= M || j + chkCase[k][2][1] >= M)
					continue;	//각 테스트 케이스가 map을 벗어나는 경우를 제외하고 전부 검사한다.
				int tmp = nMap[i][j]
					+ nMap[i + chkCase[k][0][0]][j + chkCase[k][0][1]]
					+ nMap[i + chkCase[k][1][0]][j + chkCase[k][1][1]] 
					+ nMap[i + chkCase[k][2][0]][j + chkCase[k][2][1]];
				if (MAX < tmp)
					MAX = tmp;
			}
		}
	}
	cout << MAX;

	return 0;
}