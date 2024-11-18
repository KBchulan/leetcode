#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    static bool isNumber(string s)
    {
        regex pattern("^[+-]?(\\d+\\.?|\\.\\d+|\\d+\\.\\d+)([eE][+-]?\\d+)?$");
        return regex_match(s, pattern);
    }
}; 