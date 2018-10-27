//1978 소수 찾기 https://www.acmicpc.net/problem/1978
#include <iostream>
using namespace std;

int main() {
	int n, cnt = 0;
	int num;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;

		bool ok = true;
		if (num == 1) ok = false;
		for (int j = 2; j*j <= num; j++) {
			if (num%j == 0) {
				ok = false;
				break;
			}
		}
		if (ok) cnt += 1;
	}

	cout << cnt;

	return 0;
}