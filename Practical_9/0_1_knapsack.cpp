#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Item {
    int weight, profit;
    double ratio;
};

struct Node {
    int level, profit, weight;
    double bound;
};

bool cmp(Item a, Item b) {
    return a.ratio > b.ratio;
}

double bound(Node u, int n, int W, vector<Item>& items) {
    if (u.weight >= W) return 0;

    double profitBound = u.profit;
    int j = u.level + 1;
    int totalWeight = u.weight;

    while (j < n && totalWeight + items[j].weight <= W) {
        totalWeight += items[j].weight;
        profitBound += items[j].profit;
        j++;
    }

    if (j < n)
        profitBound += (W - totalWeight) * items[j].ratio;

    return profitBound;
}

int knapsack(int W, vector<Item>& items, int n) {
    sort(items.begin(), items.end(), cmp);

    priority_queue<pair<double, Node>> pq;

    Node u, v;
    u.level = -1;
    u.profit = 0;
    u.weight = 0;
    u.bound = bound(u, n, W, items);

    pq.push({u.bound, u});

    int maxProfit = 0;

    while (!pq.empty()) {
        u = pq.top().second;
        pq.pop();

        if (u.bound <= maxProfit) continue;

        v.level = u.level + 1;

        v.weight = u.weight + items[v.level].weight;
        v.profit = u.profit + items[v.level].profit;

        if (v.weight <= W && v.profit > maxProfit)
            maxProfit = v.profit;

        v.bound = bound(v, n, W, items);
        if (v.bound > maxProfit)
            pq.push({v.bound, v});

        v.weight = u.weight;
        v.profit = u.profit;

        v.bound = bound(v, n, W, items);
        if (v.bound > maxProfit)
            pq.push({v.bound, v});
    }

    return maxProfit;
}

int main() {
    int W = 16;

    vector<Item> items = {
        {2, 40, 40.0/2},
        {5, 30, 30.0/5},
        {10, 50, 50.0/10},
        {5, 10, 10.0/5}
    };

    cout << knapsack(W, items, items.size());
}