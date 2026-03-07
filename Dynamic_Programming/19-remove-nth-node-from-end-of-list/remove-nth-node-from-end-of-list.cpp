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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* trav = head;
        int l = 0;

        while(trav != NULL) {
            l++;
            trav = trav->next;
        }

        if(n == l) {
            return head->next;
        }

        trav = head;

        for(int i = 1; i < l - n; i++) {
            trav = trav->next;
        }

        trav->next = trav->next->next;

        return head;
    }
};