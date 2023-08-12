#include <iostream>
using namespace std;

int button[1000000];

int main() {
	int N;             // 버튼의 개수
	int count = 0;     // 버튼을 눌러야 되는 횟수

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> button[i];
	}

	//켜져있는 버튼을 찾아 모두 꺼야함
	for (int i = 0; i < N; i++) {
		if (button[i] == 1) {
			count++;	// 버튼을 눌려야 하는 횟수++

			// 오른쪽 1번째 버튼 눌림 
			if (button[i + 1] == 1) {
				button[i + 1] = 0;
			}
			else {
				button[i + 1] = 1;
			}
			// 오른쪽 2번째 버튼 눌림 
			if (button[i + 2] == 1) {
				button[i + 2] = 0;
			}
			else {
				button[i + 2] = 1;
			}
		}
	}

	cout << count;

	return 0;
}