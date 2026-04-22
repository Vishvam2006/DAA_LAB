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
    vector<int> path1(n), path2(n);

    line1[0] = entry1 + stationTime[0][0];
    line2[0] = entry2 + stationTime[1][0];

    for (int i = 1; i < n; i++)
    {
        int stay1 = line1[i - 1] + stationTime[0][i];
        int switch1 = line2[i - 1] + transferTime[1][i - 1] + stationTime[0][i];

        if (stay1 <= switch1)
        {
            line1[i] = stay1;
            path1[i] = 1;
        }
        else
        {
            line1[i] = switch1;
            path1[i] = 2;
        }

        int stay2 = line2[i - 1] + stationTime[1][i];
        int switch2 = line1[i - 1] + transferTime[0][i - 1] + stationTime[1][i];

        if (stay2 <= switch2)
        {
            line2[i] = stay2;
            path2[i] = 2;
        }
        else
        {
            line2[i] = switch2;
            path2[i] = 1;
        }
    }

    int finalLine;
    int result;

    if (line1[n - 1] + exit1 <= line2[n - 1] + exit2)
    {
        result = line1[n - 1] + exit1;
        finalLine = 1;
    }
    else
    {
        result = line2[n - 1] + exit2;
        finalLine = 2;
    }

    cout << "Minimum time: " << result << endl;

    vector<int> path(n);
    path[n - 1] = finalLine;

    for (int i = n - 1; i > 0; i--)
    {
        if (path[i] == 1)
            path[i - 1] = path1[i];
        else
            path[i - 1] = path2[i];
    }

    cout << "Path: ";
    for (int i = 0; i < n; i++)
    {
        cout << "Line " << path[i] << " -> ";
    }
    cout << "End" << endl;
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