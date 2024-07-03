//https://leetcode.com/problems/reorder-list/description/
//Time: O(N)
//Space: O(1)
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        //Get the middle
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* firstHalf = head;
        ListNode* secondHalf = slow->next;
        slow->next = nullptr;

        //reverse the second half
        ListNode* previous = nullptr;
        while (secondHalf != nullptr) {
            ListNode* next = secondHalf->next;
            secondHalf->next = previous;
            previous = secondHalf;
            secondHalf = next;
        }
        secondHalf = previous;
        while (firstHalf != nullptr && secondHalf != nullptr) {
            ListNode* tmp1 = firstHalf->next;
            ListNode* tmp2 = secondHalf->next;

            firstHalf->next = secondHalf;
            secondHalf->next = tmp1;

            firstHalf = tmp1;
            secondHalf = tmp2;
        }
    }
};
