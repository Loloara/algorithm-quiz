//14888 연산자 끼워넣기 https://www.acmicpc.net/problem/14888
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, op, max=-1000000000, min=1000000000;
	cin >> n;
	vector<int> nArr(n);
	vector<int> oArr;
	for (int i = 0; i < n; i++) {
		cin >> nArr[i];
	}
	for (int i = 1; i < 5; i++) {
		cin >> op;
		for (int j = 0; j < op; j++) {
			oArr.push_back(i);		//+:1, -:2, x:3, /:4
		}
	}

	do {
		int calc = nArr[0];
		for (int i = 0; i < n - 1; i++) {
			switch (oArr[i]) {
			case 1:
				calc += nArr[i + 1];
				break;
			case 2:
				calc -= nArr[i + 1];
				break;
			case 3:
				calc *= nArr[i + 1];
				break;
			case 4:
				calc /= nArr[i + 1];
				break;
			}
		}
		if (calc > max) max = calc;
		if (calc < min) min = calc;
	} while (next_permutation(oArr.begin(), oArr.end()));

	cout << max << '\n' << min;

	return 0;
}