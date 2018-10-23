#include <iostream>
using namespace std;

int gcd(int a, int b);
int gcd_while(int a, int b);

int main() {
	int in1, in2;
	cout << "input two integer: ";
	cin >> in1 >> in2;
	cout << "gcd: " << gcd(in1, in2);

	return 0;
}

//Euclidean division by recursive function
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

//by while
int gcd_while(int a, int b) {
	int tmp;
	while (b != 0) {
		tmp = a;
		a = b;
		b = tmp % b;
	}
	return a;
}