//1476 날짜 계산 https://www.acmicpc.net/problem/1476
//문제 그대로 전부 검사
#include <iostream>
using namespace std;

int main() {
	int E, S, M;	// 범위 1부터 각 15, 28, 19 까지
	int e = 1, s = 1, m = 1;
	cin >> E >> S >> M;

	for (int year = 1; year <= 7980; year++) {
		if (E == e && S == s && M == m) {
			cout << year;
			return 0;
		}
		e++;
		s++;
		m++;
		if (e == 16)
			e = 1;
		if (s == 29)
			s = 1;
		if (m == 20)
			m = 1;
	}

	return 0;
}