#include <iostream>
#include <string>

using namespace std;

int main(void) {
	
	int A, B;
	scanf("%d %d", &A, &B);

	int num = 1; //연산 횟수
	while (true) {
		if (A == B) {
			break;
		}
		else if (A > B) {
			num = -1;
			break;
		}
		else if (B % 2 == 0) { //2로 나뉘면
			B = B / 2;
			num++;
		}
		else if (B % 10 == 1) { //맨 뒤 문자가 1이라면
			B = B / 10;
			num++;
		}
		else {
			num = -1;
			break;
		}
	
	}
	printf("%d", num);

	return 0;
}