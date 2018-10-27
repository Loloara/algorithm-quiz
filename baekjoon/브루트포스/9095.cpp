//9095 1,2,3 ���ϱ� https://www.acmicpc.net/problem/9095
//����Լ��� ����
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
	if (sum > goal) return 0;	//�Ұ����� ���
	if (sum == goal) return 1;	//������ ã�� ���
	
	int count = 0;
	for (int i = 1; i <= 3; i++)
		count += go(sum + i, goal);	//���� ���

	return count;
}