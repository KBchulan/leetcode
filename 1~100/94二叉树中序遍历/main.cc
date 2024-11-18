#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> nums;
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (root)
        {
            if (root->left)
                inorderTraversal(root->left);
            nums.emplace_back(root->val);
            if (root->right)
                inorderTraversal(root->right);
        }
        return nums;
    }
};