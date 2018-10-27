//1759 ��ȣ ����� https://www.acmicpc.net/problem/1759
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void go(int n, vector<char> cArr, string password, int i);
bool check(string password);

int main() {
	int n,l;
	cin >> l >> n;
	vector<char> cArr(n);
	for (int i = 0; i < n; i++) {
		cin >> cArr[i];
	}
	sort(cArr.begin(), cArr.end());

	go(l, cArr, "", 0);

	return 0;
}

void go(int n, vector<char> cArr, string password, int i) {
	if (password.length() == n) {
		if (check(password)) //������ ���
			cout << password << '\n';
		return; //�Ұ����� ���
	}

	if (i == cArr.size()) return;	//�Ұ����� ���
	go(n, cArr, password + cArr[i], i + 1);	//���� ���
	go(n, cArr, password, i + 1);			//���� ���
}

bool check(string password) {
	int ja = 0;
	int mo = 0;
	for (char x : password) {
		if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
			mo++;
		else
			ja++;
	}

	return mo >= 1 && ja >= 2;
}