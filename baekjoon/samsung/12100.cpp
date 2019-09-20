#include <iostream>
#include <vector>
using namespace std;

int mx = 2;

void dfs(vector<vector<int>> board, int dir, int depth) {
	int lastK;
	switch (dir) {
	case 0:	//위
		for (int j = 0; j < board.size(); j++) {
			lastK = -1;
			for (int i = 1; i < board.size(); i++) {	//합치기
				if (!board[i][j]) continue;
				for (int k = i - 1; k > lastK; k--) {
					if (!board[k][j]) continue;
					if (board[i][j] == board[k][j]) {
						board[k][j] *= 2;
						board[i][j] = 0;
						lastK = k;
						break;
					}
					else break;
				}	
			}
			for (int i = 0; i < board.size() - 1; i++) {	//위치
				if (board[i][j]) continue;
				for (int k = i + 1; k < board.size(); k++) {
					if (board[k][j]) {
						board[i][j] = board[k][j];
						board[k][j] = 0;
						break;
					}
				}
			}
		}
		break;
	case 1: //아래
		for (int j = 0; j < board.size(); j++) {
			lastK = board.size();
			for (int i = board.size()-2; i >= 0; i--) {	//합치기
				if (!board[i][j]) continue;
				for (int k = i + 1; k < lastK; k++) {
					if (!board[k][j]) continue;
					if (board[i][j] == board[k][j]) {
						board[k][j] *= 2;
						board[i][j] = 0;
						lastK = k;
						break;
					}
					else break;
				}	
			}
			for (int i = board.size()-1; i > 0; i--) {	//위치
				if (board[i][j]) continue;
				for (int k = i - 1; k >= 0; k--) {
					if (board[k][j]) {
						board[i][j] = board[k][j];
						board[k][j] = 0;
						break;
					}
				}
			}
		}
		break;
	case 2:	//왼
		for (int i = 0; i < board.size(); i++) {
			lastK = -1;
			for (int j = 1; j < board.size(); j++) {	//합치기
				if (!board[i][j]) continue;
				for (int k = j - 1; k > lastK; k--) {
					if (!board[i][k]) continue;
					if (board[i][j] == board[i][k]) {
						board[i][k] *= 2;
						board[i][j] = 0;
						lastK = k;
						break;
					}
					else break;
				}
			}
			for (int j = 0; j < board.size() - 1; j++) {	//위치
				if (board[i][j]) continue;
				for (int k = j + 1; k < board.size(); k++) {
					if (board[i][k]) {
						board[i][j] = board[i][k];
						board[i][k] = 0;
						break;
					}
				}
			}
		}
		break;
	case 3: //오른
		for (int i = 0; i < board.size(); i++) {
			lastK = board.size();
			for (int j = board.size()-2; j >= 0; j--) {	//합치기
				if (!board[i][j]) continue;
				for (int k = j + 1; k < lastK; k++) {
					if (!board[i][k]) continue;
					if (board[i][j] == board[i][k]) {
						board[i][k] *= 2;
						board[i][j] = 0;
						lastK = k;
						break;
					}
					else break;
				}
			}
			for (int j = board.size()-1; j > 0; j--) {	//위치
				if (board[i][j]) continue;
				for (int k = j - 1; k >= 0; k--) {
					if (board[i][k]) {
						board[i][j] = board[i][k];
						board[i][k] = 0;
						break;
					}
				}
			}
		}
		break;
	}

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board.size(); j++) {
			if (mx < board[i][j])
				mx = board[i][j];
		}
	}

	if (depth == 5) return;
	
	for (int i = 0; i < 4; i++)
		dfs(board, i, depth + 1);
}

int main() {
	int N;
	vector<vector<int>>	board;

	cin >> N;
	for (int i = 0; i < N; i++) {
		vector<int> vTmp;
		int tmp;

		for (int j = 0; j < N; j++) {
			cin >> tmp;
			vTmp.push_back(tmp);
		}
		board.push_back(vTmp);
	}

	for (int i = 0; i < 4; i++) 
		dfs(board, i, 1);
		

	cout << mx;

	return 0;
}