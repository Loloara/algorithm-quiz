#include <iostream>
using namespace std;

bool isPrimeNumber(int a);
bool* sieveOfEratosthenes(int n);

int main() {
	/*
	int in=1;
	while (in) {
		cin >> in;
		if (isPrimeNumber(in))
			cout << " : true" << endl;
		else
			cout << " : false" << endl;
	}
	*/
	int num, count=0;
	cout << "input number: ";
	cin >> num;
	bool* rst = sieveOfEratosthenes(num);

	for (int i = 0; i < num + 1; i++) {
		if (rst[i]) {
			cout << i << " ";
			count++;
		}
	}
	cout << endl << "number of prime number: " << count;

	return 0;
}

// BigO : 루트N
bool isPrimeNumber(int n) {
	if (n < 2) return false;
	for (int i = 2; i*i <= n; i++) {	//check integer number until root a
		if (n % i == 0)
			return false;
	}
	return true;
}

/* BigO : N log (log N)
에라토스테네스의 체라고 부르는 방식으로 작은 소수부터 그의 배수를 소수 후보에서 배제하는 방식
*/
bool* sieveOfEratosthenes(int n) {
	bool* arr = new bool[n+1];
	arr[0] = false;
	arr[1] = false;
	for (int i = 2; i < n + 1; i++)
		arr[i] = true;

	for (int i = 2; i < n + 1; i++) {
		if (arr[i]) {
			for (int j = i * 2; j < n + 1; j+=i) {	//i*2 부분은 사실 i*i 부터 검사하는게 맞으나 int범위를 초과하는 경우가 생기므로 이렇게 작성한다.
				if (j%i == 0)
					arr[j] = false;
			}
		}
	}

	return arr;
}