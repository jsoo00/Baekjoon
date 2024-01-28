#include <iostream>
using namespace std;

int max(int a, int b) {
	int c = a % b;
	while (c != 0) {
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}

int min(int a, int b) {
	return (a * b) / max(a, b);
}

int main(void){
	int N,M;
	cin >> N >> M;
	cout << max(N, M) << '\n' << min(N, M);
	return 0;
}