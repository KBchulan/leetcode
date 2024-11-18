#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (const auto &num : nums)
            mp[num]++;

        int idx = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < mp[i]; j++)
            {
                nums[idx++] = i;
            }
        }
    }
};