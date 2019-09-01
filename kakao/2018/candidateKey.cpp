#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

void dfs(int col, int size);		//��� �� ����
bool minimal(int items);			//�κ� ���� �߿� �ĺ�Ű ������ ���� (�ּҼ�)
bool isCandidate(int items);		//��� Ʃ�õ��� �����ϰ� �ĺ��������� (���ϼ�)

vector<vector<string>> rCopy;
vector<pair<vector<int>, bool>> comb;
vector<int> rst;

int solution(vector<vector<string>> relation) {
	rCopy = relation;
	int answer = 0;
	int rows, cols;
	rows = relation.size();
	cols = relation[0].size();

	for (int i = 0; i < cols; i++) {
		dfs(i, cols);
	}

	for (int i = 1; i < comb.size(); i++) {		//�������� (������ �������� ��������)
		pair<vector<int>, bool> tmp = comb[i];
		for (int j = i - 1; j >= 0; j--) {
			if (tmp.first.size() < comb[j].first.size()) {
				comb[j + 1] = comb[j];
			}
			else {
				comb[j + 1] = tmp;
				break;
			}
		}
	}

	for (int i = 0; i < comb.size();i++) {
		if (minimal(i)) {
			if (isCandidate(i)) {
				comb[i].second = true;
				answer++;
			}
		}
	}

	return answer;
}

void dfs(int col, int size) {
	if (col == size) return;
	rst.push_back(col);
	comb.push_back(make_pair(rst, false));
	for (int i = col + 1; i < size; i++) {
		dfs(i, size);
	}
	rst.pop_back();
}

bool minimal(int items) {
	bool ok = true;
	for (int i = items-1; i >= 0; i--) {
		if (comb[i].first.size() == comb[items].first.size() || !comb[i].second)
			continue;
		
		int chk = comb[i].first.size();
		for (int j : comb[i].first) {
			for (int item : comb[items].first) {
				if (j == item) {
					chk--;
					break;
				}
			}
		}

		if (!chk) {	//�ĺ�Ű�� �κ����� �߿� ����
			return false;
		}
	}

	return true;
}

bool isCandidate(int items) {
	vector<string> apd;
	for (vector<string> s : rCopy) {
		string tmp = "";
		for (int i = 0; i < s.size(); i++) {
			for (int j : comb[items].first) {
				if (i == j) tmp += s[i];
			}
		}
		apd.push_back(tmp);
	}

	for (int i = 0; i < apd.size()-1; i++) {
		for (int j = i + 1; j < apd.size(); j++) {
			if (apd[i] == apd[j]) return false;
		}
	}

	return true;
}

int main() {
	vector<string> v1{ "100","ryan","music","2" };
	vector<string> v2{ "200","apeach","math","2" };
	vector<string> v3{ "300","tube","computer","3" };
	vector<string> v4{ "400","con","computer","4" };
	vector<string> v5{ "500","muzi","music","3" };
	vector<string> v6{ "600","apeach","music","2" };
	vector<vector<string>> relation{ v1,v2,v3,v4,v5,v6 };

	cout << solution(relation);

	return 0;
}