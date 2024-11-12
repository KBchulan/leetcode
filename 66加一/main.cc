#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int idx = digits.size() - 1;
        return addNum(digits, idx);
    }

    vector<int> addNum(vector<int> &digits, int idx)
    {
        if (idx < 0)
        {
            digits.insert(digits.begin(), 1);
            return digits;
        }

        if (idx == digits.size() - 1)
        {
            digits[idx] += 1;
        }

        if (digits[idx] < 10)
            return digits;

        digits[idx] = 0;
        if (idx > 0)
            digits[idx - 1] += 1;

        return addNum(digits, idx - 1);
    }
};