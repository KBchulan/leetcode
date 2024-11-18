#include <bits/stdc++.h>

using namespace std;

bool operator==(const vector<int> &a, const vector<int> &b)
{
    if (a.size() != b.size())
        return false;

    for (auto i = 0; i < a.size(); i++)
        if (a[i] != b[i])
            return false;
    return true;
}

class Solution
{
public:
    static vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        res(nums, 0, result);
        return result;
    }

    static void res(vector<int> &nums, int currentIdx, vector<vector<int>> &result)
    {
        if (currentIdx == nums.size())
        {
            for (const auto &num : result)
                if (num == nums)
                    return;
            result.push_back(nums);
        }

        for (auto index = currentIdx; index < nums.size(); index++)
        {
            swap(nums[index], nums[currentIdx]);
            res(nums, currentIdx + 1, result);
            swap(nums[index], nums[currentIdx]);
        }
    }
};
