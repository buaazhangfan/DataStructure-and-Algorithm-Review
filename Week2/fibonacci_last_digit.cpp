#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

int fibonacci_last(int n )
{
	vector<int>result(n);
	result[0] = 0;
	result[1] = 1;
	for(int i = 2; i <= n ; i++)
	{
		result[i] = (result[i - 1] + result[i - 2]) % 10;
	}

	return result[n];
}


int main()
{
	int n = 0;
	cin >> n;
	cout << fibonacci_last(n) << '\n';
	return 0;
}