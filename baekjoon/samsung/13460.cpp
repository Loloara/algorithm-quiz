#include <iostream>
#include<vector>
#include <queue>
using namespace std;

int ri, rj, bi, bj;

typedef struct ball {
	int ri, rj, bi, bj, count;
	ball(int ri, int rj, int bi, int bj, int count) {
		this->ri = ri;
		this->rj = rj;
		this->bi = bi;
		this->bj = bj;
		this->count = count;
	}
}ball;

int solution(int N, int M, vector<vector<char>> cMap) {
	bool chk[10][10][10][10] = { false };
	bool redin, bluein;
	int tri, trj, tbi, tbj, tcount;
	queue<ball> q;
	q.push({ ri, rj, bi, bj, 1 });
	
	while (!q.empty()) {
		tri = q.front().ri;
		trj = q.front().rj;
		tbi = q.front().bi;
		tbj = q.front().bj;
		tcount = q.front().count;
		q.pop();
		if (tcount > 10) break;
		if (chk[tri][trj][tbi][tbj]) continue;
		chk[tri][trj][tbi][tbj] = true;
		
//위==================================================================
		bluein = false;
		redin = false;
		ri = tri;
		rj = trj;
		bi = tbi;
		bj = tbj;
		while (true) {
			ri--;
			if (cMap[ri][rj] == '#') {
				ri++;
				break;
			}
			if (cMap[ri][rj] == 'O') {
				redin = true;
				break;
			}
		}

		while(true) {
			bi--;
			if (cMap[bi][bj] == '#') {
				bi++;
				break;
			}
			if (cMap[bi][bj] == 'O') {
				bluein = true;
				break;
			}
		}
		
		if (redin && !bluein) 
			return tcount;
		if (ri == bi && rj == bj) {
			if (tri < tbi) bi++;
			else ri++;
		}
		if (!redin && !bluein)
			q.push({ ri,rj,bi,bj,tcount + 1 });

//아래==================================================
		bluein = false;
		redin = false;
		ri = tri;
		rj = trj;
		bi = tbi;
		bj = tbj;
		while (true) {
			ri++;
			if (cMap[ri][rj] == '#') {
				ri--;
				break;
			}
			if (cMap[ri][rj] == 'O') {
				redin = true;
				break;
			}
		}

		while (true) {
			bi++;
			if (cMap[bi][bj] == '#') {
				bi--;
				break;
			}
			if (cMap[bi][bj] == 'O') {
				bluein = true;
				break;
			}
		}

		if (redin && !bluein)
			return tcount;
		if (ri == bi && rj == bj) {
			if (tri > tbi) bi--;
			else ri--;
		}
		if (!redin && !bluein)
			q.push({ ri,rj,bi,bj,tcount + 1 });
//왼================================================================
		bluein = false;
		redin = false;
		ri = tri;
		rj = trj;
		bi = tbi;
		bj = tbj;
		while (true) {
			rj--;
			if (cMap[ri][rj] == '#') {
				rj++;
				break;
			}
			if (cMap[ri][rj] == 'O') {
				redin = true;
				break;
			}
		}

		while (true) {
			bj--;
			if (cMap[bi][bj] == '#') {
				bj++;
				break;
			}
			if (cMap[bi][bj] == 'O') {
				bluein = true;
				break;
			}
		}

		if (redin && !bluein) 
			return tcount;
		if (ri == bi && rj == bj) {
			if (trj < tbj) bj++;
			else rj++;
		}
		if (!redin && !bluein) {
			q.push({ ri,rj,bi,bj,tcount + 1 });
		}

//오른==================================================
		bluein = false;
		redin = false;
		ri = tri;
		rj = trj;
		bi = tbi;
		bj = tbj;
		while (true) {
			rj++;
			if (cMap[ri][rj] == '#') {
				rj--;
				break;
			}
			if (cMap[ri][rj] == 'O') {
				redin = true;
				break;
			}
		}

		while (true) {
			bj++;
			if (cMap[bi][bj] == '#') {
				bj--;
				break;
			}
			if (cMap[bi][bj] == 'O') {
				bluein = true;
				break;
			}
		}

		if (redin && !bluein) 
			return tcount;
		if (ri == bi && rj == bj) {
			if (trj > tbj) bj--;
			else rj--;
		}
		if (!redin && !bluein)
			q.push({ ri,rj,bi,bj,tcount + 1 });
	}

	return -1;
}

int main() {
	int N, M;
	char tmp;
	vector<vector<char>> cMap;
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		vector<char> vTmp;
		for (int j = 0; j < M; j++) {
			cin >> tmp;
			switch (tmp) {
			case 'R':
				ri = i;
				rj = j;
				tmp = '.';
				break;
			case 'B':
				bi = i;
				bj = j;
				tmp = '.';
				break;
			}
			vTmp.push_back(tmp);
		}
		cMap.push_back(vTmp);
	}

	cout << solution(N, M, cMap) << endl;

	return 0;
}