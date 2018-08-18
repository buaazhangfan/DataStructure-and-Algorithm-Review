#include<iostream>

using namespace std;


int getGCD(int a, int b)
{
	int temp = 0;
	while(b != 0)
	{
		temp = b;
		b = a % b;
		a = temp;
		if(b == 0)
			return a;

	}
	return a;
}


int main()
{
	int x;
	int y;
	cin >> x >> y;
	cout << getGCD(x, y) << endl;
	return 0;
}