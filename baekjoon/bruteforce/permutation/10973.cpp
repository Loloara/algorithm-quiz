//10973 ���� ���� https://www.acmicpc.net/problem/10973
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	if (prev_permutation(arr.begin(), arr.end())) {
		for (int i = 0; i < n; i++) {
			cout << arr[i] << ' ';
		}
	}
	else
		cout << -1;

	return 0;
}