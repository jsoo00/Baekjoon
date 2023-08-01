#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int N;
	cin >> N;
	string color;
	cin >> color;
	int rrr = 0; //연속된 빨강의 개수
	int bbb = 0;//연속된 파랑의 개수
	int result = 0; //결과값

	for (int i = 0; i < N; i++) {
		if (color[i] == 'R' && color[i + 1] != 'R') rrr++;//만약 연속된 빨강이 아니라면
		else if (color[i] == 'B' && color[i + 1] != 'B') bbb++;//만약 연속된 파랑이 아니라면
	}
	if (rrr >= bbb) result = bbb + 1; //파랑 칠한 개수 + (전체적으로 다 빨강으로 칠한 개수=1)
	else result = rrr + 1; //빨강 칠한 개수 + (전체적으로 다 파랑으로 칠한 개수=1)
	cout << result;
	return 0;
}