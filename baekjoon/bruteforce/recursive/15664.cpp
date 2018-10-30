//15664 N과 M(10) https://www.acmicpc.net/problem/15664
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr(8);
vector<int> nArr;
vector<vector<int>> ans;
bool chk[8];
void go(int index, int n, int m);

int main() {
	int n, m, num;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> num;
		nArr.push_back(num);
	}
	sort(nArr.begin(), nArr.end());
	go(0, n, m);

	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < m; j++) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}

void go(int index, int n, int m) {
	//정답인 경우
	if (index == m) {
		ans.push_back(arr);
		return;
	}

	//다음 경우
	for (int i = 0; i < n; i++) {
		if (index != 0) {
			if (nArr[i] < arr[index - 1]) continue;
		}
		if (chk[i]) continue;
		arr[index] = nArr[i];
		chk[i] = true;
		go(index + 1, n, m);
		chk[i] = false;
	}
}