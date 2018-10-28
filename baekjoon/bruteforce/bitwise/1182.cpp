//1182 부분집합의 합 https://www.acmicpc.net/problem/1182
//비트마스크로 풀기
#include <iostream>
using namespace std;

int main() {
	int n, s, ans = 0;
	int a[20];
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 1; i < (1 << n); i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j))
				sum += a[j];
		}
		if (sum == s)
			ans += 1;
	}
	cout << ans;

	return 0;
}