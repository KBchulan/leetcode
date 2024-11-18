#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    static vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;
        res(nums, 0, result);
        return result;
    }

    static void res(vector<int> &nums, int currentIdx, vector<vector<int>> &result)
    {
        if (currentIdx == nums.size() - 1)
        {
            result.push_back(nums);
            return;
        }

        for (auto index = currentIdx; index < nums.size(); index++){
            swap(nums[index], nums[currentIdx]);
            res(nums, currentIdx + 1, result);
            swap(nums[index], nums[currentIdx]);
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}