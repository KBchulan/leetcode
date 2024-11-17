#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    static vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        if (nums.size() == 0)
            return {};

        sort(nums.begin(), nums.end());

        vector<int> current;
        vector<vector<int>> result;
        backTrack(result, current, nums, 0);
        return result;
    }

private:
    static void backTrack(vector<vector<int>> &result, vector<int> &current, vector<int> &nums, int idx)
    {
        if(std::find(result.begin(), result.end(), current) == result.end())
            result.emplace_back(current);

        for (int i = idx; i < nums.size(); i++)
        {
            current.push_back(nums[i]);
            backTrack(result, current, nums, i + 1);
            current.pop_back();
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> nums = {1, 2, 2};
    vector<vector<int>> results = Solution::subsetsWithDup(nums);

    for(const auto &result : results)
    {
        for (const auto &num : result)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}