#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        if (n == 1)
            return {{"Q"}};
        if (n <= 3)
            return {};

        col = vector<bool>(n, false);
        digit = vector<bool>(2 * n - 1, false);
        crdigit = vector<bool>(2 * n - 1, false);
        vector<string> board(n, string(n, '.'));

        backTrack(n, 0, board);

        return res;
    }

private:
    vector<bool> col;
    vector<bool> digit;
    vector<bool> crdigit;
    vector<vector<string>> res;

    void backTrack(int n, int leval, vector<string> &board)
    {
        if (leval == n)
        {
            res.push_back(board);
            return;
        }

        int add = n - 1;

        for (auto i = 0; i < n; i++)
        {
            if (!col[i] && !digit[leval + i] && !crdigit[leval - i + add])
            {
                col[i] = digit[leval + i] = crdigit[leval - i + add] = true;
                board[leval][i] = 'Q';
                backTrack(n, leval + 1, board);
                board[leval][i] = '.';
                col[i] = digit[leval + i] = crdigit[leval - i + add] = false;
            }
        }
    }
};
