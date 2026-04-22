#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int weight, profit;
    double ratio;
};

bool cmp(Item a, Item b)
{
    return a.ratio > b.ratio;
}

int knapsackGreedy(int W, Item items[], int n)
{
    sort(items, items + n, cmp);

    int totalProfit = 0;

    for (int i = 0; i < n; i++)
    {
        if (items[i].weight <= W)
        {
            W -= items[i].weight;
            totalProfit += items[i].profit;
        }
    }

    return totalProfit;
}

int main()
{
    int W = 16;

    Item items[] = {
        {2, 40, 40.0/2},
        {5, 30, 30.0/5},
        {10, 50, 50.0/10},
        {5, 10, 10.0/5}
    };

    int n = 4;

    cout << knapsackGreedy(W, items, n);
}