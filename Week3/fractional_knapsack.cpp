#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

struct good
{
    int weights;
    int value;
    double unit;
};

bool comp(const good &a, const good &b){
    return a.unit > b.unit;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
    double value = 0.0;
    int num = weights.size();
    int MaxCapacity = capacity;
    int a = capacity;
    vector<good>pervalue(num);
    for(int i = 0; i < num; i++)
    {
        good onegood;
        onegood.weights = weights[i];
        onegood.value = values[i];
        onegood.unit = (double)values[i] / weights[i];
        pervalue[i] = onegood;
    }
    sort(pervalue.begin(), pervalue.end(), comp);
    //for(vector<good>::iterator it = pervalue.begin(); it != pervalue.end(); it++)
    //std::cout<<(*it).unit<<" "<<(*it).weights<<std::endl;
    //reverse(pervalue.begin(), pervalue.end());
    for(int j = 0; j < num; j++)
    {
        if(MaxCapacity == 0)
            return value;
        a = std::min(pervalue[j].weights, MaxCapacity);
        value += (double)(a * pervalue[j].unit);
        pervalue[j].weights -= a;
        MaxCapacity -= a;
    }

    return value;
}

int main() {
    int n ;
    int capacity;
    std::cin >> n >> capacity;
    vector<int> values(n);
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        std::cin >> values[i] >> weights[i];
    }



    double optimal_value = get_optimal_value(capacity, weights, values);

    std::cout.precision(10);
    std::cout << optimal_value << std::endl;
    return 0;
}
