#include <iostream>
#include <string>
using namespace std;

int N1, N2, T;
string ants1, ants2;

void initData() {
	string tmp;
	cin >> N1 >> N2;
	cin >> ants1 >> ants2;
	cin >> T;
}

void printAnswer() {
	char* answer = new char[N1 + N2 + 1];
	for (int i = 0; i < N1; i++) {
		int index = (N1 - 1 - i);
		if (i < T) {
			index += (T - i);
		}
		if (index >= N1 + N2 - 1 - i) {
			answer[N1 + N2 - 1 - i] = ants1[i];
		}
		else {
			answer[index] = ants1[i];
		}
	}

	for (int i = 0; i < N2; i++) {
		int index = (N1 + i);
		if (i < T) {
			index -= (T - i);
		}
		if (index <= i) {
			answer[i] = ants2[i];
		}
		else {
			answer[index] = ants2[i];
		}
	}
	answer[N1 + N2] = '\0';

	cout << answer;
}

void solution() {
	initData();
	printAnswer();
}

int main() {
	solution();

	return 0;
}