//6603 로또 https://www.acmicpc.net/problem/6603
//재귀함수로 구현
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> lotto;
void go(vector<int> nArr, int index, int cnt);

int main() {
	int n;
	do {
		cin >> n;
		vector<int> nArr(n);
		for (int i = 0; i < n; i++)
			cin >> nArr[i];
		go(nArr, 0, 0);
		cout << '\n';
	} while (n != 0);
	return 0;
}

void go(vector<int> nArr, int index, int cnt) {
	if (cnt == 6) {
		for (int x : lotto)
			cout << x << ' ';
		cout << '\n';
		return;
	}
	if (index == nArr.size()) return;
	lotto.push_back(nArr[index]);
	go(nArr, index + 1, cnt + 1);
	lotto.pop_back();
	go(nArr, index + 1, cnt);
}