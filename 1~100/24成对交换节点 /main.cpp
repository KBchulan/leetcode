//
// Created by whx on 24-10-25.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    static ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* current = &dummy;

        while (current->next != nullptr && current->next->next != nullptr) {
            ListNode* first = current->next;
            ListNode* second = first->next;

            first->next = second->next;
            second->next = first;
            current->next = second;

            current = first;
        }

        return dummy.next;
    }
};