#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

long long MaxPairwiseProduct(const vector<int> &numbers) 
{
    int n = numbers.size();

    int index1 = -1;
    for (int x = 0; x < n; ++x)
    {
        if (index1 == -1 || numbers[x] > numbers[index1])
            index1 = x;
    }

    int index2 = -1;
    for (int y = 0; y < n; ++y)
    {
        if (y != index1 && (index2 == -1 || numbers[y] > numbers[index2]))

            index2 = y;
    }

    return (long long)(numbers[index1] * numbers[index2]);

}

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }
    
    long long result = MaxPairwiseProduct(numbers);
    cout << result << "\n";
    return 0;
}

