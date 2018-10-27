//15658 연산자 끼워넣기(2) https ://www.acmicpc.net/problem/15658
//재귀함수 사용
#include <iostream>
using namespace std;

int ansMax = -1000000000;
int ansMin = 1000000000;
void go(int n, int* nArr, int index, int add, int sub, int mul, int div, int cur);

int main() {
	int n, nArr[11], add, sub, mul, div;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> nArr[i];
	cin >> add >> sub >> mul >> div;

	go(n, nArr, 1, add, sub, mul, div, nArr[0]);
	cout << ansMax << '\n' << ansMin;

	return 0;
}

void go(int n, int* nArr, int index, int add, int sub, int mul, int div, int cur) {
	if (add < 0 || sub < 0 || mul < 0 || div < 0) return;	//불가능한 경우
	if (n == index) {	//정답인 경우
		if (ansMax < cur) ansMax = cur;
		if (ansMin > cur) ansMin = cur;
		return;
	}

	//다음 경우
	go(n, nArr, index + 1, add - 1, sub, mul, div, cur + nArr[index]);
	go(n, nArr, index + 1, add, sub - 1, mul, div, cur - nArr[index]);
	go(n, nArr, index + 1, add, sub, mul - 1, div, cur * nArr[index]);
	go(n, nArr, index + 1, add, sub, mul, div - 1, cur / nArr[index]);
}