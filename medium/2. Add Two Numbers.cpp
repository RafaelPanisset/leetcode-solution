//https://leetcode.com/problems/add-two-numbers/
//Time: O(n)
//Space: O(n)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            tail->next = new ListNode(sum % 10);
            carry = sum / 10;
            tail = tail->next;
        }
        return dummy.next;
    }
};
