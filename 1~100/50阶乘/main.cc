#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    static double myPow(double x, int n)
    {
        if (n < 0)
            x = 1. / x;

        long num = labs(n);
        double res = 1.;

        while (num)
        {
            if (num % 2)
                res *= x;

            x *= x;
            num >>= 1;
        }

        return res;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cout << Solution::myPow(2.10000, 3) << '\n';
}