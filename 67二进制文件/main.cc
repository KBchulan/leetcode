#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string result;
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;

        // 从右向左逐位相加
        while (i >= 0 || j >= 0 || carry > 0)
        {
            int sum = carry;
            if (i >= 0)
                sum += a[i--] - '0';
            if (j >= 0)
                sum += b[j--] - '0';

            carry = sum / 2;
            result = char(sum % 2 + '0') + result;
        }

        return result;
    }
};