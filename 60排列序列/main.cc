#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    static string getPermutation(int n, int k)
    {
        string res = "";
        vector<int> nums(n, 0);
        vector<int> factorial(n, 1);

        for (size_t i = 0; i < n; i++)
            nums[i] = i + 1;

        for (size_t i = 1; i < n; i++)
            factorial[i] = factorial[i - 1] * i;

        k--;

        for (size_t i = 0; i < n; i++)
        {
            int index = k / factorial[n - 1 - i];
            res += to_string(nums[index]);
            nums.erase(nums.begin() + index);
            k %= factorial[n - 1 - i];
        }
        return res;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cout << Solution::getPermutation(4, 9) << endl;
}