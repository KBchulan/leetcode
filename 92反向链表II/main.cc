#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    explicit ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left == right)
            return head;
        
        ListNode dummy(0, head);

        vector<int> nums;
        while (head != nullptr)
        {
            nums.emplace_back(head->val);
            head = head->next;
        }

        std::reverse(nums.begin() + left, nums.begin() + right + 1);

        ListNode* tmp = dummy.next;
        for(int i = 0; i < right; i++)
        {
            tmp->val = nums[i];

            if(tmp->next != nullptr)
                tmp = tmp->next;
        }

        return dummy.next;
    }
};

int main()
{
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
    std::reverse(nums.begin() + 2, nums.begin() + 5);

    for(const auto &num : nums)
    {
        cout << num << " ";
    }
}