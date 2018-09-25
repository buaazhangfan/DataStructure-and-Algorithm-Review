#include <iostream>
#include <vector>

using std::vector;
using namespace std;
int maxmium(int a, int b, int c)
{
    return max(max(a, b), c);
}

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {

    int m = a.size();
    int n = b.size();
    int k = c.size();
    int x;

    vector<vector<vector<int> > > len(m+1, vector<vector<int>>(n+1, vector<int>(k+1, 0)));

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int p = 1; p <= k; p++)
            {

                if (a[i - 1] == b[j - 1] && b[j - 1] == c[p - 1])
                len[i][j][p] = len[i-1][j-1][p-1] + 1;

                else
                len[i][j][p] = maxmium(len[i-1][j][p], len[i][j-1][p], len[i][j][p-1]);


                //std::cout << len[i][j][k];

            }
        }
    }
    return len[m][n][k];
}

int main() {
    size_t an;
    std::cin >> an;
    vector<int> a(an);
    for (size_t i = 0; i < an; i++) {
        std::cin >> a[i];
    }
    size_t bn;
    std::cin >> bn;
    vector<int> b(bn);
    for (size_t i = 0; i < bn; i++) {
        std::cin >> b[i];
    }
    size_t cn;
    std::cin >> cn;
    vector<int> c(cn);
    for (size_t i = 0; i < cn; i++) {
        std::cin >> c[i];
    }
    std::cout << lcs3(a, b, c) << std::endl;
}
