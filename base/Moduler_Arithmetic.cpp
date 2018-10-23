#include <string>
using namespace std;

/* 나머지 연산
+,x 에 있어서 수들의 합(곱)의 모듈러는 나머지들 끼리의 합(곱)의 모듈러와 같다.
정답의 숫자가 커지는 경우 문제에서 종종 요구한다.
*/
int main() {
	int a = 24, b = 16, c = 3;
	printf("(%d + %d) %% %d = %d\n", a, b, c, (a + b) % c);
	printf("((%d %% %d) + (%d %% %d)) %% %d = %d\n\n", a, c, b, c, c, ((a%c) + (b%c)) % c);

	printf("(%d x %d) %% %d = %d\n", a, b, c, (a * b) % c);
	printf("((%d %% %d) x (%d %% %d)) %% %d = %d\n\n", a, c, b, c, c, ((a%c) * (b%c)) % c);

	printf("(%d - %d) %% %d = %d\n", a, b, c, c, (a - b) % c);	//a > b
	printf("((%d %% %d) - (%d %% %d) + %d) %% %d = %d\n", a, c, b, c, c, c, ((a%c) - (b%c) + c) % c);

	return 0;
}