#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int N;
    int next;
    cin >> N;
    vector<int>T(N+2),P(N+2);
    vector<int>dp(N+2,0);
    for (int i = 1; i <= N; i++) {
        cin >> T[i] >> P[i];
    }

    for (int i = N; i > 0; i--) {
        next = i + T[i];
        if (next > N+1) {
            dp[i] = dp[i + 1];
        }
        else {
            dp[i] = max(dp[i + 1], dp[next] + P[i]);
        }

    }

    cout << dp[1] << endl;

    return 0;
}