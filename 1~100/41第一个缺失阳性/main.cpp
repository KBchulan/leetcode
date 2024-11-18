#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    static int firstMissingPositive(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        sort(nums.begin(), nums.end());

        for (const auto &num : nums)
            mp[num]++;

        for (auto i = 1; i <= nums.size(); i++)
        {
            if (!mp.contains(i))
            {
                return i;
            }
        }

        return nums.back() + 1;
    }
};

int main()
{
    vector<int> nums = {1, 2, 0};
    cout << Solution::firstMissingPositive(nums);
    return 0;
}