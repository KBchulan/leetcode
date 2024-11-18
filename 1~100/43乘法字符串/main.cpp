#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
            return "0";

        int nums1_size = num1.size(), nums2_size = num2.size();
        vector<int> result(nums1_size + nums2_size, 0);

        // mul
        for (int i = nums1_size - 1; i >= 0; i--)
        {
            for (int j = nums2_size - 1; j >= 0; j--)
            {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = result[i + j + 1] + mul;
                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }

        string res = "";
        for (const auto &num : result)
        {
            if (!(res.empty() && num == 0))
                res.push_back(num + '0');
        }

        return res.empty() ? "0" : res;
    }
};