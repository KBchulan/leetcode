//
// Created by whx on 24-10-27.
//

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    static int strStr(const string& haystack, const string& needle) {
        if(const size_t pos = haystack.find(needle);
            pos != std::string::npos) {
            return static_cast<int>(pos);
        }
        return -1;
    }
};

int main() {
    auto a(string("hello,myself"));
    auto b(string("myself"));
    cout << Solution::strStr(a, b) << endl;
}