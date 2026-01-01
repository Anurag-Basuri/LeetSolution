class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head) return head;

        ListNode dummy(0, head);
        ListNode *prev = &dummy, *i = head, *j = head;

        while (i) {
            if (i->val >= x) {
                j = i;
                while (j->next && j->next->val >= x)
                    j = j->next;

                if (!j->next) {   // nothing smaller ahead
                    i = i->next;
                    continue;
                }

                ListNode* temp = j->next;
                j->next = temp->next;
                prev->next = temp;
                temp->next = i;
                prev = temp;
            } else {
                prev = i;
                i = i->next;
            }
        }
        return dummy.next;
    }
};
