// 2309 일곱 난쟁이 https://www.acmicpc.net/problem/2309
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int sum = 0, a, b;
	int inArr[9] = {};
	for (int i = 0; i < 9; i++) {
		cin >> inArr[i];
		sum += inArr[i];
	}

	sort(begin(inArr), end(inArr));

	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - (inArr[i] + inArr[j]) == 100) {	//두명을 선택하여 합에서 뺸 것이 100을 만족하면 정답
				for (int k = 0; k < 9; k++) {
					if (k != i && k != j) {
						cout << inArr[k] << endl;
					}
				}
				return 0;
			}
		}
	}


	return 0;
}