#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	int N, K;
	cin >> N >> K;
	queue<int> circle;

	//circle에 수를 대입 7654321
	for (int i = 1; i <= N; i++) {
		circle.push(i);
	}

	cout << "<";

	//circle이 빌 때까지
	while (!circle.empty()) {
		for (int i = 1; i < K; i++) {
			circle.push(circle.front()); //7654321에서 front가 1이므로 17654321로 front를 대입함.   //2 1765432  
			circle.pop(); //17654321에서 1이 빠져서 1765432이 됨. //이 과정을 K-1번 만큼 반복       //2176543  
		}
		if (circle.size() != 1) {
			cout << circle.front() << ", "; //3이 출력됨
		}
		else if (circle.size() == 1) {
			cout << circle.front();
		}
		circle.pop(); //3을 없앰
	}
	cout << ">";
	return 0;
}