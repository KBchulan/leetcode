//
// Created by whx on 24-10-18.
//

#include <limits>
#include <string>
#include <iostream>

class Solution {
    using ll = long long;
public:
    static int reverse(const int x) {
        const std::string rever = std::to_string(x);
        std::string result;

        if(rever.front() == '-')
            result = "-" + std::string(rever.rbegin(), rever.rend());
        else
            result = std::string(rever.rbegin(), rever.rend());

        const ll int_result = std::stoll(result);
        if(int_result < std::numeric_limits<int>::min() ||
            int_result > std::numeric_limits<int>::max() )
            return 0;

        return static_cast<int>(int_result);
    }
};

int main(int argc, char** argv) {
    std::ios::sync_with_stdio(NULL);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cout << Solution::reverse(-123) << std::endl;
    std::cout << Solution::reverse(5946) << std::endl;
    std::cout << Solution::reverse(-12661615) << std::endl;
    std::cout << Solution::reverse(-1288546416) << std::endl;
    return 0;
}