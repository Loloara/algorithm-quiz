//6603 �ζ� https://www.acmicpc.net/problem/6603
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	while(true){
		cin >> n;
		if (!n) break;
		vector<int> arr(n);		//���� S
		vector<int> chk(n);		//6���� 1, �������� 0�� ������ �迭�Ͽ� ����� ���� ���� Ȯ���Ѵ�.
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			if (i < 6)
				chk[i] = 1;
			else
				chk[i] = 0;
		}
		do {
			for (int i = 0; i < n; i++) {
				if (chk[i])
					cout << arr[i] << ' ';
			}
			cout << '\n';
		} while (prev_permutation(chk.begin(), chk.end()));
		cout << '\n';
	}

	return 0;
}