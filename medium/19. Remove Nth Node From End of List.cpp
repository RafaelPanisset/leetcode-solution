//https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
//Time: O(n)
//Space: O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy = ListNode(0);
        dummy.next = head;
        ListNode* node1 = &dummy;
        ListNode* node2 = &dummy;
        node1 = &dummy;
        node2 = &dummy;

        for (int i = 0; i <= n; i++) {
            if (!node2)
                return head;
            node2 = node2->next;
        }

        while (node2) {
            node2 = node2->next;
            node1 = node1->next;
        }
        ListNode* temp = node1->next;
        node1->next = node1->next->next;
        delete temp;
        return dummy.next;
    }
};
