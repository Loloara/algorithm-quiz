//14501 ��� https://www.acmicpc.net/problem/14501
#include <iostream>
#include <vector>
using namespace std;

int ans = 0;
void go(vector<int> tArr, vector<int> pArr, int index, int sum);

int main() {
	int n;
	cin >> n;
	vector<int> tArr(n);
	vector<int> pArr(n);
	for (int i = 0; i < n; i++) {
		cin >> tArr[i] >> pArr[i];
	}

	go(tArr, pArr, 0, 0);
	cout << ans;

	return 0;
}

void go(vector<int> tArr, vector<int> pArr, int index, int sum){
	if (sum > ans && index == tArr.size()) ans = sum;		//������ ���
	if (index >= tArr.size()) return;						//�Ұ����� ���
	
	//���� ���
	go(tArr, pArr, index + tArr[index], sum + pArr[index]);
	go(tArr, pArr, index + 1, sum);
}