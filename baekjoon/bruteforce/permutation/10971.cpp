//10971 외판원 순회2 https://www.acmicpc.net/problem/10971
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, min = 1000000000;
	int wArr[10][10];
	cin >> n;
	vector<int> nArr;
	for (int i = 0; i < n; i++) {
		nArr.push_back(i);
		for (int j = 0; j < n; j++) {
			cin >> wArr[i][j];
		}
	}

	do {
		if (nArr[0]) break;			//끝과 처음이 연결된 순회이기 때문에 앞자리는 0 하나로 고정시키면 중복을 피할 수 있다.
		int sum = 0;
		bool ok = true;
		for (int i = 0; i < n-1; i++) {
			if (!wArr[nArr[i]][nArr[i + 1]]) {	//길이 존재하지 않음
				ok = false;
				break;
			}
			sum += wArr[nArr[i]][nArr[i + 1]];
		}
		if (!wArr[nArr[n - 1]][nArr[0]]) {	//마지막 도시에서 처음 도시
			ok = false;
		}
		sum += wArr[nArr[n-1]][nArr[0]];
		if (ok && (sum < min)) min = sum;
	} while (next_permutation(nArr.begin(), nArr.end()));

	cout << min;

	return 0;
}