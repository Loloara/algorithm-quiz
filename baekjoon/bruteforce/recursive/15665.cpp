//15665 N과 M(11) https://www.acmicpc.net/problem/15665
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr(8);
vector<int> nArr;
vector<vector<int>> ans;
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
		arr[index] = nArr[i];
		go(index + 1, n, m);
	}
}