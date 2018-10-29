//15655 N과 M(6) https://www.acmicpc.net/problem/15655
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[8];
vector<int> nArr;
void go(int index, int n, int m);

int main() {
	int n, m, num;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> num;
		nArr.push_back(num);
	}
	sort(nArr.begin(), nArr.end());
	go(0, n, m);

	return 0;
}

void go(int index, int n, int m) {
	//정답인 경우
	if (index == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	//다음 경우
	for (int i = 0; i < n; i++) {
		if (index != 0) {
			if (arr[index - 1] >= nArr[i]) continue;
		}
		arr[index] = nArr[i];
		go(index + 1, n, m);
	}
}