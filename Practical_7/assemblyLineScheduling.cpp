#include <iostream>
#include <vector>
using namespace std;

int minVal(int a, int b)
{
    return (a < b) ? a : b;
}

void assemblyLineScheduling(int n, int entry1, int entry2, vector<vector<int>> stationTime, vector<vector<int>> transferTime, int exit1, int exit2)
{
    vector<int> line1(n), line2(n);

    line1[0] = entry1 + stationTime[0][0];
    line2[0] = entry2 + stationTime[1][0];

    for (int i = 1; i < n; i++)
    {
        int stayLine1 = line1[i - 1] + stationTime[0][i];
        int switchLine1 = line2[i - 1] + transferTime[1][i - 1] + stationTime[0][i];
        line1[i] = minVal(stayLine1, switchLine1);

        int stayLine2 = line2[i - 1] + stationTime[1][i];
        int switchLine2 = line1[i - 1] + transferTime[0][i - 1] + stationTime[1][i];
        line2[i] = minVal(stayLine2, switchLine2);
    }

    int result = minVal(line1[n - 1] + exit1, line2[n - 1] + exit2);
    cout << result << endl;
}

int main()
{
    vector<vector<int>> stationTime = {
        {7, 9, 3, 4, 8},
        {8, 5, 6, 4, 5}};

    vector<vector<int>> transferTime = {
        {2, 3, 1, 3},
        {2, 1, 2, 2}};

    int entry1 = 2;
    int entry2 = 4;

    assemblyLineScheduling(5, entry1, entry2, stationTime, transferTime, 3, 6);

    return 0;
}