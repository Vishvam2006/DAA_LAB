#include <iostream>
#include <vector>
using namespace std;

int knapsack(int i, int W, vector<int> &wt, vector<int> &val, int n)
{
    if (i == n || W == 0)
        return 0;

    int exclude = knapsack(i + 1, W, wt, val, n);

    int include = 0;
    if (wt[i] <= W)
    {
        include = val[i] + knapsack(i + 1, W - wt[i], wt, val, n);
    }

    return max(include, exclude);
}

int main()
{
    vector<int> wt = {2, 5, 10, 5};
    vector<int> val = {40, 30, 50, 10};
    int W = 16;

    cout << knapsack(0, W, wt, val, wt.size());

    return 0;
}