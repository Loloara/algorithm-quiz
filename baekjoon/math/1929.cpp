//1929 소수 구하기 https://www.acmicpc.net/problem/1929
#include <iostream>
using namespace std;

int main() {
	int M, N;
	bool arr[1000001];
	cin >> M >> N;
	
	for (int i = 2; i <= N; i++)
		arr[i] = true;

	for (int i = 2; i * 2 < N; i++) {
		if (arr[i]) {
			for (int j = i * 2; j <= N; j += i) {
				arr[j] = false;
			}
		}
	}

	for (int i = M; i <= N; i++) {
		if (arr[i]) cout << i << '\n';
	}

	return 0;
}