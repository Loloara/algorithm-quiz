//1182 �κ������� �� https://www.acmicpc.net/problem/1182
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans = 0;
void go(vector<int> nArr, int index, int sum, int goal);

int main() {
	int n, s;
	cin >> n >> s;
	vector<int> nArr(n);
	for (int i = 0; i < n; i++)
		cin >> nArr[i];
	
	go(nArr, 0, 0, s);
	if (s == 0)
		ans -= 1;
	cout << ans;

	return 0;
}

void go(vector<int> nArr, int index, int sum, int goal) {
	if (index == nArr.size()) {				//�Ұ����� ���
		if (sum == goal) ans += 1;			//������ ���
		return;
	}

	//���� ���
	go(nArr, index + 1, sum + nArr[index], goal);
	go(nArr, index + 1, sum, goal);
}