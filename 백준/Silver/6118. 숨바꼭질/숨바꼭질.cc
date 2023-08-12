#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
vector<int> v[20001];
int visit[20001]; 
int maxidx, maxnum, maxcnt;

void bfs() {
	queue<int> q;
	q.push(1); //첫 방문은 무조건 정점 1임
	visit[1] = 1; //1을 방문한 것으로 간주
	while (!q.empty()) { //큐가 빌 때까지
		int x = q.front(); //x에 큐 맨 앞을 삽입
		q.pop(); //삽입햇으니 제거
		for (int i = 0; i < v[x].size(); i++) { //정점과 이어져 있는 개수만큼 for문을 돌림
			int nx = v[x][i]; // nx = x와 연결돼 있는 정점
			if (!visit[nx]) { //if문에서 true가 반환되는 경우는 0이 아닐때 , 0인 경우만 false가 반환됨 . 즉 여기서는 !visit[nx]가 0이 아니면을 뜻함.
				visit[nx] = visit[x] + 1; //visit이 나타내는 것 = 거리
				q.push(nx);
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	for (int a, b, i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(b); //v[a] = b , b2 , b3  와 연결된 정점의 개수 = v[a].size() //b들의 인덱스가  i임 (위의 int nx = v[x][i];에서 )
		v[b].push_back(a);//양방향이라서 반대도 해줌
	}
	bfs();
	for (int i = 2; i <= N; i++) {
		if (visit[i] > maxnum) {
			maxnum = visit[i]; //거리
			maxidx = i; //정점
			maxcnt = 1; //개수
		}
		else if (visit[i] == maxnum) //거리가 같은 경우가 있으면
			maxcnt++;//개수 증가

	}
	cout << maxidx << " " << maxnum - 1 << " " << maxcnt;
}