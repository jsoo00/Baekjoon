#include <iostream>
#include <queue>
#include <functional>    // greater, less
using namespace std;

void sol(int n) {
    priority_queue<int, vector<int>, greater<int>> pq; //오름차순으로 정렬됨
    int temp;
    for (int i = 0; i < n * n; i++) {
        cin >> temp;
        pq.push(temp);
        if (pq.size() > n) pq.pop(); //pq에는 5개만 저장함
    }
    cout << pq.top();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    sol(n);
}