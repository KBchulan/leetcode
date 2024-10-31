#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    static int search(vector<int> &nums, int target)
    {
        int result = -1;
        for (auto i = 0; i < nums.size(); i++)
        {
            if(nums[i] == target){
                return i;
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

    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    cout << Solution::search(nums, target) << endl;

    return 0;
}