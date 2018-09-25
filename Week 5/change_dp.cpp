#include <iostream>
#include <vector>

using namespace std;

int get_change(int m) {

	int coins[3] = {1, 3, 4};
	vector<int>nums(m + 1, m + 1);
	nums[0] = 0;

	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (coins[j] <= i)
				nums[i] = min(nums[i], nums[i - coins[j]] + 1);
		}
	}

	return nums[m];

}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
