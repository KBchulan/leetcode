//
// Created by whx on 24-10-17.
//

#include <string>
#include <iostream>

class Solution {
public:
    static std::string convert(const std::string& s, const int numRows) {
        if (numRows == 1)
            return s;

        std::string result;
        const int fixed_dis = (numRows - 1) * 2;

        for (auto i = 0; i < numRows; i++) {
            int j = i;
            while (j < s.size()) {
                result += s[j];
                if (i != 0 && i != numRows -1) {
                    if (const int tmp = j + fixed_dis - i * 2;
                        tmp < s.size()) {
                        result += s[tmp];
                    }
                }
                j += fixed_dis;
            }
        }
        return result;
    }
};

int main(int argc, char **argv) {
    std::ios::sync_with_stdio(NULL);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    const std::string str = "PAYPALISHIRING";
    constexpr int row = 3;

    std::cout << Solution::convert(str, row) << std::endl;

}