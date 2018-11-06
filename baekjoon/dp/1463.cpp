//1463 1로 만들기 https://www.acmicpc.net/problem/1463
#include <iostream>
#include <algorithm>
using namespace std;

int mem[1000001] = { 0 };
int go(int index);

int main() {
	int N;
	cin >> N;
	cout << go(N);

	return 0;
}

int go(int index) {
	int a=1000000, b=1000000, c;
	if (index == 1) return 0;
	if (mem[index] != 0) return mem[index];

	if (index % 3 == 0) a = go(index / 3) + 1;
	if (index % 2 == 0) b = go(index / 2) + 1;
	c = go(index - 1) + 1;
	mem[index] = min(min(a, b), c);

	return mem[index];
}