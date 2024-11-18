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
    ListNode *partition(ListNode *head, int x)
    {
        if(head == nullptr || head->next == nullptr)
            return head;

        ListNode dummy(0, head);

        vector<int> min_nums;
        vector<int> max_nums;

        while (head != nullptr)
        {
            if(head->val < x)
                min_nums.emplace_back(head->val);
            else
                max_nums.emplace_back(head->val);
        }

        ListNode *tmp = dummy.next;
        for(const auto& num: min_nums)
        {
            tmp->val = num;
            
            if(num != min_nums.back())
                tmp = tmp->next;
        }       

        if(!max_nums.empty())
        {
            tmp = tmp->next;
            for(const auto& num : max_nums)
            {
                tmp->val = num;
            
                if(num != max_nums.back())
                    tmp = tmp->next;
            }
        }

        return dummy.next;
    }
};