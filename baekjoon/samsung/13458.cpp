#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int N, B, C;
	int A[1000000];
	long long ans = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	cin >> B >> C;

	for (int i = 0; i < N; i++) {
		A[i] -= B;
		ans++;
		if(A[i]>0)
			ans += ceil((double)A[i] / C);
	}

	cout << ans;

	return 0;
}