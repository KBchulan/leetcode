//
// Created by whx on 24-10-28.
//

#include <cmath>
#include <cassert>
#include <iostream>

class Solution {
public:
    static int divide(const int dividend, const int divisor) {
        assert(divisor != 0);
        if (dividend == std::numeric_limits<int>::min() && divisor == -1) {
            return std::numeric_limits<int>::max();
        }
        const int ans = static_cast<int>(std::trunc(static_cast<double>(dividend) / static_cast<double>(divisor) ));
        return ans;
    }
};

int main() {
    std::cout << Solution::divide(-11, 3) << std::endl;
}