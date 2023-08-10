#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int N, S, M; //곡의 개수, 시작 볼륨, 최대볼륨
	cin >> N >> S >> M; //곡의 개수, 시작 볼륨, 최대볼륨 입력받음
	
	int vol[51]; //조절할 수 있는 볼륨 크기
	for (int i = 1; i <= N; i++) {
		cin >> vol[i]; //조절할 수 있는 볼륨 크기를 입력 받음
	}

	int dp[51][1001]; //[곡의 차례][곡의 볼륨] //dp[N][M]을 의미 //0 1 2 3 ...1000까지 볼륨 가능하니까 배열크기가 1001임
	//dp테이블 초기화
	for (int i = 0; i <= N; i++) {
		fill(dp[i], dp[i] + (M + 1), -1); //dp 테이블 -1로 초기화
	}
	dp[0][S] = 1; // 원래 볼륨 S로 시작이 가능함을 의미 //dp[1][C] = 1 첫번째 곡의 볼륨은 C로 연주가 가능하단 의미 
	
	int result = -1; //연주할 수 없으면 -1을 출력
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (dp[i-1][j] == 1) {
				if (j + vol[i] <= M) {
					dp[i][j + vol[i]] = 1;
				}
				if (j - vol[i] >= 0) {
					dp[i][j - vol[i]] = 1;
				}
			}
		}
	}
	for (int j = 0; j <= M; j++) {
		if (dp[N][j] == 1) { //N번째 곡(마지막 곡)에서 볼륨 j로 연주가 가능하다면
			result = max(j, result); //볼륨의 최댓값을 result로 함.
		}
	}
	cout << result;
	return 0;
}