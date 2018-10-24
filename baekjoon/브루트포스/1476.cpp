//1476 날짜 계산 https://www.acmicpc.net/problem/1476
//나머지 계산을 통한 정답 도출
#include <iostream>
using namespace std;

int main() {
	int year = 0;
	int e, s, m;	// 범위 1부터 각 15, 28, 19 까지
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