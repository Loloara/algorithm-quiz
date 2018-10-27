//6588 �������� ���� https://www.acmicpc.net/problem/6588
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);	//iostream stdio ���� ����ȭ ����
	cin.tie(nullptr);					//cout�� cin tie ��� ����

	bool primeN[1000001] = {};
	vector<int> primeArr;
	for (int i = 2; i * 2 < 1000000; i++) {
		if (primeN[i] == false) {
			primeArr.push_back(i);
			for (int j = i * 2; j <= 1000000; j += i) {
				primeN[j] = true;
			}
		}
	}
	
	int n;
	while(true) {
		cin >> n;
		if (!n) break;
		for (int x : primeArr) {
			if (primeN[n-x] == false) {
				cout << n << " = " << x << " + " << n - x << '\n';
				break;
			}
		}
	}

	return 0;
}