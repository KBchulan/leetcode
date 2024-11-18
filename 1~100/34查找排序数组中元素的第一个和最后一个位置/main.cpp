#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    static vector<int> searchRange(vector<int> &nums, int target)
    {
         std::vector<int> result = {-1, -1};
        std::once_flag startFlag;

        for (int i = 0; i < nums.size(); ++i) 
        {
            if (nums[i] == target) 
            {
                std::call_once(startFlag, [&]() 
                {
                    result[0] = i;
                });
                result[1] = i;
            }
        }

        return result;
    }
};

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> nums = {2, 2};
    int target = 2;

    vector<int> result = Solution::searchRange(nums, target);
    for (const auto &res : result)
    {
        cout << res << " ";
    }
}