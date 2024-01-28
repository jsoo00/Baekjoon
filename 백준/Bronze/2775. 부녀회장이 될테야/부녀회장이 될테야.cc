#include <iostream>
#include <vector>
using namespace std;

int main(void){
	int T,k,n;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> k; cin >> n;
		vector <vector<int>> dp(k+10,vector<int>(n+10));
		for (int i = 1; i <= n; i++) {
			dp[0][i] = i;
		}
		for (int i = 1; i <= k; i++) {
			for (int j = 1; j <= n; j++) {
				for (int l = 1; l <= j; l++) {
					dp[i][j] += dp[i - 1][l];
				}
			}
		}
		cout << dp[k][n] << '\n';
	}
	
	return 0;
}