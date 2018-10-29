//15652 N�� M(4) https://www.acmicpc.net/problem/15652
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
	//������ ���
	if (index == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	
	//���� ���
	for (int i = 0; i < n; i++) {
		if (i+1 < arr[index - 1]) continue;
		arr[index] = i + 1;
		go(index + 1, n, m);
	}
}