#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        for(const auto& num : nums)
        {
            if(num == target)
                return true;
        }
        return false;
    }
};