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
	vector<vector<int>> mBoard;			//x,y map 초기화
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

	for (int i = 0; i < mBoard.size(); i++) {	//blocks 저장
		for (int j = 0; j < mBoard[i].size(); j++) {
			if (!mBoard[i][j]) continue; //0인 경우 패스
			if (mchk[mBoard[i][j]]) continue; //이미 체크함
			mchk[mBoard[i][j]] = true;

			int caseN = chkBlcok(i, j, mBoard);	//없앨 가능성이 있는 모양인지 체크
			if (caseN != -1) {	//해당 블록의 x,y 좌표와 블럭 ID 저장
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
	while (keep) {	//맵에서 블록을 지웠으면 계속 검사
		keep = false;
		for (int i = 0; i < keys.size(); i++) {
			bool chk2 = true;
			int yMin = blocks[keys[i]][0].second;
			for (int j = 0; j < blocks[keys[i]].size(); j++) { //지워질 후보 블럭의 원소들
				if (blocks[keys[i]][j].second + 1 == mBoard.size() - 1) continue;	//y값이 map에 가장 위에 있으면 검사 안해
				if (mBoard[blocks[keys[i]][j].first][blocks[keys[i]][j].second + 1] == keys[i]) continue; //이 블럭 바로위에 같은 블록 있으면 검사 안해
				if (blocks[keys[i]][j].second > yMin) continue;	//이전 검사 블럭들보다 y값이 높으면 검사 안해

				bool chk1 = true;
				for (int k = blocks[keys[i]][j].second + 1; k < mBoard.size(); k++) {
					if (mBoard[blocks[keys[i]][j].first][k]) {		//블럭의 y라인에 가로막는 다른 블록이 없는가
						chk1 = false;
						break;
					}
				}
				if (!chk1) {	// 윗부분에 하나라도 다른 블럭이 있으면 X
					chk2 = false;
					break;
				}
			}
			if (chk2) {
				keep = true;
				answer++;
				for (int j = 0; j < blocks[keys[i]].size(); j++) { //맵에서 해당 블록 지우기
					mBoard[blocks[keys[i]][j].first][blocks[keys[i]][j].second] = 0;
				}
				keys.erase(keys.begin()+i);	//지울 후보 블록에서 삭제
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