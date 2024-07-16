#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int num;
	int isOdd=0;
	vector<int>odd;
	for (int i = 0; i < 7; i++)
	{
		cin >> num;
		if (num % 2 != 0)
		{
			isOdd += num;
			odd.push_back(num);
		}
	}
	if(isOdd==0)
	{
		cout << "-1" << endl;
		return 0;
	}
	else
	{
		cout << isOdd << endl;
	}
	cout<<*min_element(odd.begin(), odd.end());
	return 0;
}