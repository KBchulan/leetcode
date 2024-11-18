#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
	static int minPathSum(vector<vector<int>> &grid)
	{
		int m = static_cast<int>(grid.size());
		int n = static_cast<int>(grid[0].size());

		vector<vector<int>> dp(m, vector<int>(n, 0));
		dp[0][0] = grid[0][0];

		// 初始化第一行
		for (int j = 1; j < n; j++)
			dp[0][j] = dp[0][j - 1] + grid[0][j];

		// 初始化第一列
		for (int i = 1; i < m; i++)
			dp[i][0] = dp[i - 1][0] + grid[i][0];

		// 计算其他位置的最小路径和
		for (int i = 1; i < m; i++)
			for (int j = 1; j < n; j++)
				dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];

		return dp[m - 1][n - 1];
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<vector<int>> nums = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
	cout << Solution::minPathSum(nums) << endl;

	return 0;
}