#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	int tmp;
	for (int i = 0; i < n; i++) {
		int tmp = arr1[i] | arr2[i];
		string sTmp = "";
		while(sTmp.size() != n) {
			if (tmp % 2) sTmp = "#" + sTmp;
			else sTmp = " " + sTmp;
			tmp /= 2;
		}
		answer.push_back(sTmp);
	}

	return answer;
}

int main() {
	cout << "첫번째" << endl;
	for (string s : solution(5, vector<int> {9, 20, 28, 18, 11}, vector<int> {30, 1, 21, 17, 28}))
		cout << s << endl;

	cout << "두번째" << endl;
	for (string s : solution(6, vector<int> {46, 33, 33, 22, 31, 50}, vector<int> {27, 56, 19, 14, 14, 10}))
		cout << s << endl;

	return 0;
}