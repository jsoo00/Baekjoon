#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int num;
	int sum = 0;
	vector<int>n(5);
	for (int i = 0; i < 5; i++)
	{
		cin >> num;
		n[i] = num;
		sum += num;
	}
	sort(n.begin(), n.end());
	cout <<sum/5<<endl<< n[2];

}