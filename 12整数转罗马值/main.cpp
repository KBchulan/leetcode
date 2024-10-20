//
// Created by whx on 24-10-20.
//

#include <map>
#include <string>
#include <iostream>
#include <unordered_map>

class Solution {
public:
    static std::string intToRoman(int& num) {
        std::map<int, std::string> my_map;
        my_map.insert(std::make_pair(1000, "M"));
        my_map.insert(std::make_pair(900, "CM"));
        my_map.insert(std::make_pair(500, "D"));
        my_map.insert(std::make_pair(400, "CD"));
        my_map.insert(std::make_pair(100, "C"));
        my_map.insert(std::make_pair(90, "XC"));
        my_map.insert(std::make_pair(50, "L"));
        my_map.insert(std::make_pair(40, "XL"));
        my_map.insert(std::make_pair(10, "X"));
        my_map.insert(std::make_pair(9, "IX"));
        my_map.insert(std::make_pair(5, "V"));
        my_map.insert(std::make_pair(4, "IV"));
        my_map.insert(std::make_pair(1, "I"));

        std::string result;
        while(num) {
            for (auto it = my_map.rbegin(); it != my_map.rend(); it++) {
                while(num >= it->first) {
                    num -= it->first;
                    result += it->second;
                }
            }
        }
        return result;
    }

};

// c++20
/**class Solution {
public:
    static std::string intToRoman(int& num) {
        std::map<int, std::string> my_map;
        my_map.insert(std::make_pair(1000, "M"));
        my_map.insert(std::make_pair(900, "CM"));
        my_map.insert(std::make_pair(500, "D"));
        my_map.insert(std::make_pair(400, "CD"));
        my_map.insert(std::make_pair(100, "C"));
        my_map.insert(std::make_pair(90, "XC"));
        my_map.insert(std::make_pair(50, "L"));
        my_map.insert(std::make_pair(40, "XL"));
        my_map.insert(std::make_pair(10, "X"));
        my_map.insert(std::make_pair(9, "IX"));
        my_map.insert(std::make_pair(5, "V"));
        my_map.insert(std::make_pair(4, "IV"));
        my_map.insert(std::make_pair(1, "I"));

        std::string result;
        while(num) {
            for (const auto& [fst, snd] : std::ranges::reverse_view(my_map)) {
                while(num >= fst) {
                    num -= fst;
                    result += snd;
                }
            }
        }
        return result;
    }

};**/

int main(int argc,char **argv) {
    std::ios::sync_with_stdio(NULL);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int num = 58;
    std::cout << Solution::intToRoman(num) << std::endl;
}