#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector < vector<int>> cases = { {1,2,1}, {0,0,1},
								{1,0,0}, {0,1,2},
								{1,2,2}, {0,0,1},
								{1,2,0}, {0,0,1},
								{1,1,1}, {0,1,2} };

int chkBlcok(int x, int y, vector<vector<int>> mBoard) {
	for (int i = 0; i < cases.size(); i += 2) {
		int chk3 = 0;
		for (int j = 0; j < 3; j++) {
			if (x + cases[i][j] > mBoard.size()-1 || y + cases[i + 1][j] > mBoard.size() - 1) break;
			if (mBoard[x + cases[i][j]][y + cases[i + 1][j]] != mBoard[x][y]) break;
			chk3++;
		}
		if (chk3 == 3) return i;
	}

	return -1;
}

int solution(vector<vector<int>> board) {
	vector<vector<int>> mBoard;			//x,y map �ʱ�ȭ
	for (int i = 0; i < board.size(); i++) {
		vector<int> tmp;
		for (int j = board.size() - 1; j >= 0; j--) {
			tmp.push_back(board[j][i]);
		}
		mBoard.push_back(tmp);
	}

	map<int, vector<pair<int, int>>> blocks;
	map<int, bool> mchk;
	vector<int> keys;

	for (int i = 0; i < mBoard.size(); i++) {	//blocks ����
		for (int j = 0; j < mBoard[i].size(); j++) {
			if (!mBoard[i][j]) continue; //0�� ��� �н�
			if (mchk[mBoard[i][j]]) continue; //�̹� üũ��
			mchk[mBoard[i][j]] = true;

			int caseN = chkBlcok(i, j, mBoard);	//���� ���ɼ��� �ִ� ������� üũ
			if (caseN != -1) {	//�ش� ����� x,y ��ǥ�� �� ID ����
				vector<pair<int, int>> tmp;
				tmp.push_back(make_pair(i, j));
				tmp.push_back(make_pair(i + cases[caseN][0], j + cases[caseN + 1][0]));
				tmp.push_back(make_pair(i + cases[caseN][1], j + cases[caseN + 1][1]));
				tmp.push_back(make_pair(i + cases[caseN][2], j + cases[caseN + 1][2]));
				blocks[mBoard[i][j]] = tmp;
				keys.push_back(mBoard[i][j]);
			}
		}
	}

	bool keep = true;
	int answer = 0;
	while (keep) {	//�ʿ��� ����� �������� ��� �˻�
		keep = false;
		for (int i = 0; i < keys.size(); i++) {
			bool chk2 = true;
			int yMin = blocks[keys[i]][0].second;
			for (int j = 0; j < blocks[keys[i]].size(); j++) { //������ �ĺ� ���� ���ҵ�
				if (blocks[keys[i]][j].second + 1 == mBoard.size() - 1) continue;	//y���� map�� ���� ���� ������ �˻� ����
				if (mBoard[blocks[keys[i]][j].first][blocks[keys[i]][j].second + 1] == keys[i]) continue; //�� �� �ٷ����� ���� ��� ������ �˻� ����
				if (blocks[keys[i]][j].second > yMin) continue;	//���� �˻� ���麸�� y���� ������ �˻� ����

				bool chk1 = true;
				for (int k = blocks[keys[i]][j].second + 1; k < mBoard.size(); k++) {
					if (mBoard[blocks[keys[i]][j].first][k]) {		//���� y���ο� ���θ��� �ٸ� ����� ���°�
						chk1 = false;
						break;
					}
				}
				if (!chk1) {	// ���κп� �ϳ��� �ٸ� ���� ������ X
					chk2 = false;
					break;
				}
			}
			if (chk2) {
				keep = true;
				answer++;
				for (int j = 0; j < blocks[keys[i]].size(); j++) { //�ʿ��� �ش� ��� �����
					mBoard[blocks[keys[i]][j].first][blocks[keys[i]][j].second] = 0;
				}
				keys.erase(keys.begin()+i);	//���� �ĺ� ��Ͽ��� ����
				break;
			}
		}
	}

	return answer;
}

int main() {
	vector<vector<int>> input{ {0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,4,0,0,0},{0,0,0,0,0,4,4,0,0,0},{0,0,0,0,3,0,4,0,0,0},{0,0,0,2,3,0,0,0,5,5},{1,2,2,2,3,3,0,0,0,5},{1,1,1,0,0,0,0,0,0,5} };
	cout << solution(input);

	return 0;
}