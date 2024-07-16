#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a, b, c;

int main(void) {
	cin >> a >> b >> c;
	vector<int>num(3);
	num[0] = a; num[1] = b; num[2] = c;
	sort(num.begin(), num.end());
	for (int i = 0; i < 3; i++)
	{
		cout << num[i]<<' ';
	}
}


