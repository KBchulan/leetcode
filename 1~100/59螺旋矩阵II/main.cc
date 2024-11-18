#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    static vector<vector<int>> generateMatrix(int n)
    {
        int num = 1;

        int cols = n, rows = n;
        int col = -1, row = 0;
        int dir = 1;

        vector<vector<int>> res(n, vector<int>(n, 0));

        while (cols > 0 && rows > 0)
        {
            for (int i = 0; i < cols; i++)
            {
                col += dir;
                res[row][col] = num++;
            }
            rows--;

            for (int i = 0; i < rows; i++)
            {
                row += dir;
                res[row][col] = num++;
            }

            cols--;
            dir *= -1;
        }
        return res;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<vector<int>> res;
    res = Solution::generateMatrix(3);
    for (const auto &line : res)
    {
        for (const auto &num : line)
            cout << num << " ";
        cout << '\n';
    }
}