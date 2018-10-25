//6603 로또 https://www.acmicpc.net/problem/6603
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	while(true){
		cin >> n;
		if (!n) break;
		vector<int> arr(n);		//집합 S
		vector<int> chk(n);		//6개는 1, 나머지는 0인 순열로 배열하여 경우의 수를 전부 확인한다.
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