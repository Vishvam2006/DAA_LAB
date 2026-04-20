#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> leftRow, vector<int> lowerDiagonal, vector<int> upperDiagonal, int n)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0)
            {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;

                solve(col + 1, board, ans, leftRow, lowerDiagonal, upperDiagonal, n);

                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n){
        vector<vector<string>> ans;

        vector<string> board(n);

        string s(n, '.');

        for(int i = 0; i < n; i++){
            board[i] = s;
        }

        vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);

        solve(0, board, ans, leftRow, lowerDiagonal, upperDiagonal, n);

        return ans;
    }
};

int main()
{
    int n;
    cout << "Enter N: ";
    cin >> n;

    Solution obj;
    vector<vector<string>> solutions = obj.solveNQueens(n);

    cout << "Number of solutions: " << solutions.size() << endl;

    // for (int i = 0; i < solutions.size(); i++)
    // {
    //     cout << "Solution " << i + 1 << ":" << endl;
    //     for (string row : solutions[i])
    //     {
    //         cout << " ";
    //         cout << row << endl;
    //     }
    //     cout << endl;
    // }

    return 0;
}