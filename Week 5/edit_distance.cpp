#include <iostream>
#include <string>
#include <vector>
using namespace std;

using std::string;


int minimum(int a, int b, int c)
{
	return min(a, min(b, c));
}
int edit_distance(const string &str1, const string &str2) {

	int m = str1.size();
	int n = str2.size();

	vector<vector<int>> dis(m+1, vector<int>(n+1, 0));
	for (int i = 0; i < m; i++)
		dis[i][0] = i;
	for (int j = 0; j < n; j++)
		dis[0][j] = j;
        
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                    dis[i][j] = dis[i - 1][j - 1];
                else
                    dis[i][j] = minimum((dis[i - 1][j - 1] + 1), (dis[i - 1][j] + 1), (dis[i][j - 1] + 1));
            }
        }
        
        return dis[m][n];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
