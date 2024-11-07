#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    static void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                swap(matrix[i][j], matrix[j][i]);

        for (int i = 0; i < n; i++)
            reverse(matrix[i].begin(), matrix[i].end());
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<vector<int>> matix = {
        {1, 2, 3}, {4, 5, 6}, {7, 8, 9}
    };

    Solution::rotate(matix);

    for (const auto &nums : matix)
    {
        for (const auto &num : nums)
            cout << num << " ";
        cout << endl;
    }

    return 0;
}