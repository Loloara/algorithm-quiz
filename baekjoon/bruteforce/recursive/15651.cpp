//15651 N과 M(3) https://www.acmicpc.net/problem/15651
#include <iostream>
using namespace std;

int arr[8];
void go(int index, int n, int m);

int main() {
	int n, m;
	cin >> n >> m;
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
		arr[index] = i + 1;
		go(index + 1, n, m);
	}
}