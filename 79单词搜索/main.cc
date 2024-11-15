#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    static bool exist(vector<vector<char>> &board, string word)
    {
        for (size_t i = 0; i < board.size(); i++)
        {
            for (size_t j = 0; j < board[0].size(); j++)
            {
                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }

private:
    inline static vector<pair<int, int>> direction = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    static bool dfs(vector<vector<char>> &board, string &word, int i, int j, int pos)
    {
        if (pos == word.size())
            return true;

        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[pos])
        {
            return false;
        }

        char tmp = board[i][j];
        board[i][j] = '#';

        for (const auto &dir : direction)
        {
            int newI = i + dir.first;
            int newJ = j + dir.second;
            if (dfs(board, word, newI, newJ, pos + 1))
                return true;
        }
        board[i][j] = tmp;
        return false;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};
    cout << std::boolalpha << Solution::exist(board, "ABCCED") << endl;
}