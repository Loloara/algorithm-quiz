#include <iostream>
#include <string>
using namespace std;

string words[6];
string rows[3];
string cols[3];
bool visited[6];
bool isFinished = false;

void initData() {
	for (int i = 0; i < 6; i++) {
		cin >> words[i];
		visited[i] = false;
	}
}

bool chkValidation() {
	bool chkRows[3] = { false };
	bool chkCols[3] = { false };
	bool keep = true;
	for (int i = 0; i < 6; i++) if (keep) {
		keep = false;
		for (int j = 0; j < 3; j++) if (!keep) {
			if (!chkRows[j]) {
				if (words[i].compare(rows[j]) == 0) {
					chkRows[j] = true;
					keep = true;
					continue;
				}
			}
			if (!chkCols[j]) {
				if (words[i].compare(cols[j]) == 0) {
					chkCols[j] = true;
					keep = true;
					continue;
				}
			}
		}
	}

	return keep;
}

void dfs(int depth) {
	if (depth == 3) {
		for (int i = 0; i < 3; i++) {
			cols[i] = "";
			cols[i] += rows[0][i];
			cols[i] += rows[1][i];
			cols[i] += rows[2][i];
		}
		if (chkValidation()) {
			isFinished = true;
		}
		return;
	}

	for (int i = 0; i < 6; i++) if(!visited[i] && !isFinished) {
		rows[depth] = words[i];
		visited[i] = true;
		dfs(depth + 1);
		visited[i] = false;
	}
}


void solution() {
	initData();
	dfs(0);
	if (!isFinished) {
		cout << 0;
	}
	else {
		for (int i = 0; i < 3; i++) {
			cout << rows[i] << endl;
		}
	}
}

int main() {
	solution();

	return 0;
}