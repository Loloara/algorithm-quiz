//1476 ��¥ ��� https://www.acmicpc.net/problem/1476
//������ ����� ���� ���� ����
#include <iostream>
using namespace std;

int main() {
	int year = 0;
	int e, s, m;	// ���� 1���� �� 15, 28, 19 ����
	cin >> e >> s >> m;
	e--;
	s--;
	m--;

	while (!(e == year % 15 && s == year % 28 && m == year % 19)) {
		year++;
	}

	cout << year+1;

	return 0;
}