//9095 1,2,3 더하기 https://www.acmicpc.net/problem/9095
//재귀함수로 구현
#include <iostream>
using namespace std;

int go(int sum, int goal);

int main() {
	int n, goal;
	cin >> n;

	for(int i=0;i<n;i++){
		cin >> goal;
		cout << go(0, goal) << '\n';
	}

	return 0;
}

int go(int sum, int goal) {
	if (sum > goal) return 0;	//불가능한 경우
	if (sum == goal) return 1;	//정답을 찾은 경우
	
	int count = 0;
	for (int i = 1; i <= 3; i++)
		count += go(sum + i, goal);	//다음 경우

	return count;
}