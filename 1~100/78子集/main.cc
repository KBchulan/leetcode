#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    static void backtrack(vector<vector<int>> &result, vector<int> &path, const vector<int> &nums, int start)
    {
        result.push_back(path);

        for (int i = start; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            backtrack(result, path, nums, i + 1);
            path.pop_back();
        }
    }

public:
    static vector<vector<int>> subsets(const vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> path;
        backtrack(result, path, nums, 0);
        return result;
    }
    
};

int main()
{
    vector<vector<int>> result = Solution::subsets({1, 2, 3});
    for (const auto &num : result)
    {
        for (const auto &item : num)
        {
            cout << item << " ";
        }
        cout << num.size() << '\n';
    }
}