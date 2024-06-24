/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 //https://leetcode.com/problems/reverse-linked-list/
 //Time: o(n)
 //Space: o(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head)
            return nullptr;

        ListNode* current = head;
        ListNode* previous = nullptr;
        ListNode* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        return previous;
    }
};
