// 2309 �ϰ� ������ https://www.acmicpc.net/problem/2309
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
			if (sum - (inArr[i] + inArr[j]) == 100) {	//�θ��� �����Ͽ� �տ��� �A ���� 100�� �����ϸ� ����
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