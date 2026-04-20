#include <iostream>
#include <vector>
using namespace std;

int maxValue = 0;

void knapsack(int i, int n, int W, vector<int>& wt, vector<int>& val,
              int currWeight, int currValue) {
    
    if (i == n) {
        if (currValue > maxValue)
            maxValue = currValue;
        return;
    }

    if (currWeight + wt[i] <= W) {
        knapsack(i + 1, n, W, wt, val,
                 currWeight + wt[i],
                 currValue + val[i]);
    }

    knapsack(i + 1, n, W, wt, val,
             currWeight, currValue);
}

int main() {
    vector<int> wt = {1, 3, 4, 5};
    vector<int> val = {1, 4, 5, 7};
    int W = 7;

    knapsack(0, wt.size(), W, wt, val, 0, 0);

    cout << maxValue;
}