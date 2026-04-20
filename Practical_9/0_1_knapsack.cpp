#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Item {
    int w, p;
    double r;
};

struct Node {
    int level, profit, weight;
    double bound;
};

bool cmp(Item a, Item b) {
    return a.r > b.r;
}


