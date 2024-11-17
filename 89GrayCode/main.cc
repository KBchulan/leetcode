#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    static vector<int> grayCode(int n)
    {
        vector<int> result = {0};

        for (int i = 0; i < n; i++)
        {
            int size = result.size();
            for (int j = size - 1; j >= 0; j--)
            {
                result.push_back(result[j] | (1 << i));
            }
        }

        return result;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> nums = Solution::grayCode(3);

    for (const auto &num : nums)
        cout << num << " ";
    cout << '\n';
}