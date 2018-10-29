//15649 N�� M (1) https://www.acmicpc.net/problem/15649
#include <iostream>
using namespace std;

bool chk[8] = {};
int arr[8];
void go(int index, int n, int m);

int main() {
	int n, m;
	cin >> n >> m;

	go(0, n, m);

	return 0;
}

void go(int index, int n, int m) {
	//������ ���
	if (index == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	//���� ���
	for (int i = 0; i < n; i++) {
		if (chk[i]) continue;
		chk[i] = true;
		arr[index] = i+1;
		go(index + 1, n, m);
		chk[i] = false;
	}
}