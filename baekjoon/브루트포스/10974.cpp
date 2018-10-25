//10974 ��� ���� https://www.acmicpc.net/problem/10974
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
		cout << '\n';					// �� endl�� '\n' ���� 20�� �����ٰ� �Ѵ�. (endl ���� �ð��ʰ�)
	} while (next_permutation(arr.begin(), arr.end()));

	return 0;
}