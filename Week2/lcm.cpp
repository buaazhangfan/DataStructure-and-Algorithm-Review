#include <iostream>


long long getGCD(long long a, long long b)
{
	long long temp = 0;
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

long long lcm_naive(long long a, long long b) 
{
	long long GCD =(long long) getGCD(a, b);

	long long mul = a * b ;
	long long result = mul / GCD;


  return result;
}

int main() 
{
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_naive(a, b) << std::endl;
  return 0;
}
