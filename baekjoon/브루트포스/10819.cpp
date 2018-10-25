//10819 차이를 최대로 https://www.acmicpc.net/problem/10819
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, max = 0;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	do {
		int sum = 0;
		for (int i = 0; i < n - 1; i++) {
			sum += abs(arr[i] - arr[i + 1]);
		}
		if (max < sum)
			max = sum;
	} while (next_permutation(arr.begin(), arr.end()));
	
	cout << max;

	return 0;
}