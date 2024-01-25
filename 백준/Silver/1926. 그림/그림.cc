#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>>paint(500, vector<int>(500,0));
int paint_area = 0;
int paint_max = 0;
int paint_count=0;
int visited[500][500];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void dfs(int x, int y) {
	paint_area++;
	visited[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];
		if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m) {
			if(!visited[next_x][next_y] && paint[next_x][next_y] == 1) {
				dfs(next_x, next_y);
			}
		}
		
	}
	
}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> paint[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (paint[i][j] == 1 && !visited[i][j]) {
				dfs(i, j);
				paint_max = max(paint_area, paint_max);
				paint_area = 0;
				paint_count += 1;
			}
			
		}
	}
	
	cout << paint_count << '\n' << paint_max;

	return 0;
}