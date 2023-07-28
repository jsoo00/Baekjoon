#include <iostream>
using namespace std;

int main(void) {
	int n; //계단의 개수
	cin >> n;
	int dp[300]; 
	int s[300];

	for (int i = 1; i <= n; i++) {
		cin >> s[i]; //각 계단의 점수를 입력받음
	}
	/*점화식 구해보면... 이렇게 된당

dp[1] = s[1] //첫번째 계단

dp[2] = s[1] + s[2]  -> 이게 dp[2] = s[2]보다는 더하는 수가 많으니까 항상 더 큼
dp[2] = s[2]

dp[3] = s[1] + s[3] -> 1칸 2칸 이동
dp[3] = s[2] + s[3] -> 2칸 1칸 이동

dp[4] = s[1] + s[2] + s[4] -> 1 1 2
dp[4] = s[1] + s[3] + s[4] -> 1 2 1
<dp[4] = s[2] + s[3] + s[4] -> 2 1 1 >->이건 안 됨..

dp[5] = s[1] + s[2] + s[4] + s[5] -> 1 1 2 1
dp[5] = s[1] + s[3] + s[5] -> 1 2 2
dp[5] = s[2] + s[3] + s[5] -> 2 1 2
dp[5] = s[2] + s[4] + s[5] -> 2 2 1
*/
	dp[1] = s[1];
	dp[2] = s[1] + s[2];
	
	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 3] + s[i - 1] + s[i], dp[i - 2] + s[i]);
	}

	cout << dp[n];

	return 0;
}