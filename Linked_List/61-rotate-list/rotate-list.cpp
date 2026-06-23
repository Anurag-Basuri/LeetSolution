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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) {
            return head;
        }

        int len = 1;
        ListNode* trav = head;

        while(trav->next != NULL) {
            len++;
            trav = trav->next;
        }

        k %= len;
        if(k == 0) return head;

        ListNode* trav2 = head;
        for(int i = 0; i < len - k - 1; i++)
            trav2 = trav2->next;
        
        ListNode* newHead = trav2->next;
        trav2->next = NULL;
        trav->next = head;

        return newHead;
    }
};