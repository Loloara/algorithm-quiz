//9613 GCD гу https://www.acmicpc.net/problem/9613
#include <iostream>
#include <vector>
using namespace std;

int GCD(int a, int b);

int main() {
	int t, n;
	cin >> t;
	while (t--){
		cin >> n;
		vector<int> nArr(n);
		long long sum = 0;
		for (int i = 0; i < n; i++)
			cin >> nArr[i];
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				sum += GCD(nArr[i], nArr[j]);
			}
		}
		cout << sum << '\n';
	}

	return 0;
}

int GCD(int a, int b) {
	if (b == 0) return a;
	return GCD(b, a%b);
}