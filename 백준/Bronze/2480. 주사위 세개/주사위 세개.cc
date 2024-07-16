#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a, b, c,prize;

int main(void) {
	cin >> a >> b >> c;
	vector<int>num(3);
	num[0] = a; num[1] = b; num[2] = c;
	sort(num.begin(), num.end());
	if (a!=b && b!=c && c!=a)
	{
		prize = num[2] * 100;
	}
	else
	{
		if (a != b && a != c)//a만 다름
		{
			prize = 1000 + b * 100;
		}
		else if (b!=a && b!=c)//b만 다름
		{
			prize = 1000 + a * 100;
		}
		else if(c!=a && c!=b)//c만 다름
		{
			prize = 1000 + b * 100;
		}
		else//셋 다 같음
		{
			prize = 10000 + a * 1000;
		}
	}
	cout << prize;
}


