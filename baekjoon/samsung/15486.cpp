#include <iostream>
using namespace std;

#define MAX(X, Y) X > Y ? X : Y
#define MX_SIZE 1500001

struct TB {
	int day, pay;
}tb[MX_SIZE];

int mem[MX_SIZE];
int N, ans;

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> tb[i].day >> tb[i].pay;

	for (int i = 1; i <= N + 1; i++) {
		ans = MAX(ans, mem[i]);
		if (i + tb[i].day > N + 1) continue;
		mem[i + tb[i].day] = MAX(ans + tb[i].pay, mem[i + tb[i].day]);
	}

	cout << ans;

	return 0;
}