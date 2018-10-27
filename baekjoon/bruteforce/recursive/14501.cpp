//14501 퇴사 https://www.acmicpc.net/problem/14501
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
	if (sum > ans && index == tArr.size()) ans = sum;		//정답인 경우
	if (index >= tArr.size()) return;						//불가능한 경우
	
	//다음 경우
	go(tArr, pArr, index + tArr[index], sum + pArr[index]);
	go(tArr, pArr, index + 1, sum);
}