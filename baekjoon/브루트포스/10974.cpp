//10974 모든 순열 https://www.acmicpc.net/problem/10974
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
	}

	do {
		for (int i = 0; i < n; i++)
			cout << arr[i] << ' ';
		cout << '\n';					// ★ endl이 '\n' 보다 20배 느리다고 한다. (endl 사용시 시간초과)
	} while (next_permutation(arr.begin(), arr.end()));

	return 0;
}