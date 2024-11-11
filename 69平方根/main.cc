#include <bits/stdc++.h>

using namespace std;

int getLastIndex(int l, int h, std::function<bool(int)> match)
{
    while (l <= h)
    {
        int mid = l + ((h - l) >> 1);
        if (match(mid))
            l = mid + 1;
        else
            h = mid - 1;
    }
    return l - 1;
}

class Solution
{
public:
    static int mySqrt(int x)
    {
        return getLastIndex(0, x, [&](int64_t a)
                            { return a * a <= x; });
    }
};

int main()
{
    cout << Solution::mySqrt(8) << endl;
}