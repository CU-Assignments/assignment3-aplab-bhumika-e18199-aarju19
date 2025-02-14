class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head; // Edge case: empty list or single node

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        while (head) {
            if (head->next && head->val == head->next->val) {
                // Skip all duplicate values
                while (head->next && head->val == head->next->val) {
                    head = head->next;
                }
                prev->next = head->next; // Remove duplicates
            } else {
                prev = prev->next; // Move forward if no duplicates
            }
            head = head->next;
        }

        return dummy->next;
    }
};
