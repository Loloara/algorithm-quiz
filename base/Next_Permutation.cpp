// 다음 순열 및 이전 순열 구하는 함수
#include <iostream>
using namespace std;

bool next_permutation(int *a, int n);
bool prev_permutation(int *a, int n);

int main() {
	int arr[7] = { 1,2,3,4,5,6,7 };
	do {	//모든 순열 출력
		for (int i = 0; i < 7; i++)
			cout << arr[i] << ' ';
		cout << endl;
	} while (next_permutation(arr, 7));

	return 0;
}

bool next_permutation(int *a, int n) {
	int i = n - 1;
	while (i > 0 && a[i - 1] >= a[i]) i -= 1;
	if (i <= 0) return false;
	
	int j = n - 1;
	while (a[j] <= a[i - 1]) j -= 1;
	swap(a[i - 1], a[j]);

	j = n - 1;
	while (i < j) {
		swap(a[i], a[j]);
		i += 1; j -= 1;
	}
	return true;
}

bool prev_permutation(int *a, int n) {
	int i = n - 1;
	while (i > 0 && a[i - 1] <= a[i]) i -= 1;
	if (i <= 0) return false;

	int j = n - 1;
	while (a[j] >= a[i - 1]) j -= 1;
	swap(a[i - 1], a[j]);

	j = n - 1;
	while (i < j) {
		swap(a[i], a[j]);
		i += 1; j -= 1;
	}
	return true;
}