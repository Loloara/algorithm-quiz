#include <string>
using namespace std;

/* ������ ����
+,x �� �־ ������ ��(��)�� ��ⷯ�� �������� ������ ��(��)�� ��ⷯ�� ����.
������ ���ڰ� Ŀ���� ��� �������� ���� �䱸�Ѵ�.
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