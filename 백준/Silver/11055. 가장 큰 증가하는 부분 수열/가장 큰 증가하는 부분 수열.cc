#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int N;
	int arr[1001] = { 0, };
	int dp[1001] = { 0, }; //합
	int result = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i]; //입력 받음
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[j],dp[i]);//dp = {4 104 2 54 114}이 됨. ->앞의 값들 중에서 가장 큰 거를 대입
			}
		}
		dp[i] += arr[i];//dp = {4 100 2 50 60}이 됨. ->원래 값 arr[i]를 더해주는 용도
		result = max(dp[i], result); //dp에서 가장 큰 값이 출력되도록 함
	}

	cout << result;

	return 0;
}