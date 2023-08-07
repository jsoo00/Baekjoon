#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int N;
	cin >> N;
	int cost[3];
	int color_cost[1001][3];
	color_cost[0][0] = 0; //0번 집을 빨강으로 칠할 때 지금까지 칠한 최소 비용
	color_cost[0][1] = 0; //0번 집을 초록으로 칠할 때 지금까지 칠한 최소 비용
	color_cost[0][2] = 0; //0번 집을 파랑으로 칠할 때 지금까지 칠한 최소 비용

	for (int i = 1; i <= N; i++) {//1번 집부터 N번 집까지 
		cin >> cost[0] >> cost[1] >> cost[2];
		color_cost[i][0] = min(color_cost[i - 1][1], color_cost[i - 1][2]) + cost[0];
		color_cost[i][1] = min(color_cost[i - 1][0], color_cost[i - 1][2]) + cost[1];
		color_cost[i][2] = min(color_cost[i - 1][0], color_cost[i - 1][1]) + cost[2];
	}
	cout << min(color_cost[N][0],min(color_cost[N][1], color_cost[N][2]));
	return 0;
}