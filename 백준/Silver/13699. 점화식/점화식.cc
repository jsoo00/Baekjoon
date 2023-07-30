#include <iostream>
using namespace std;

int main() {
	int n;
	long long t[36] = { 0, }; //0으로 초기화
	//N의 범위는 0부터 35까지이므로 16번째 줄에서 t[35]를 접근하기 위해서는 t의 크기가 최소 36 이상이어야 한다.
	cin >> n;

	t[0] = 1;

	for (int i = 1; i < n + 1; i++) {
		for (int j = 0; j < i; j++) {
			t[i] += t[j] * t[i - j - 1];
		}
	}

	cout << t[n];

	return 0;
}