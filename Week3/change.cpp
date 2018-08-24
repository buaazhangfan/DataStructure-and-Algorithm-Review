#include <iostream>

int get_change(int m) {
	int num = 0;

	int value[3] = {10, 5, 1};
	while(m > 0)
	{
		for(int i = 0; i < 3; i++)
		{
			int a = m / value[i];
			m = m - a * value[i];
			num = num + a;
			if(m == 0)
				return num;
		}
	}
  return num;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
