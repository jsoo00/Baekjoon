#include <iostream>
using namespace std;

int main(void) {
	int T,N; //테스트케이스 수, 날의 수
	int stock[1000000] = { 0, }; //날 별 주가
	long long profit=0;
	int max=0;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> stock[i]; 
		}
		profit = 0;
		max = 0;
		for (int i = N - 1; i >= 0; i--) {
			if (stock[i] < max) {
				profit += (max - stock[i]);
			}
			else {
				max = stock[i];
			}
		}
		cout << profit << '\n';
	}
	return 0;
}