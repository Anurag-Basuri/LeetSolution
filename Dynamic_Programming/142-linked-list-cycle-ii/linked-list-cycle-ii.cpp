/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> store;
        ListNode* trav = head;

        while(trav != NULL) {
            store.insert(trav);

            trav = trav->next;

            if(store.find(trav) != store.end()) return trav;
        }

        return NULL;
    }
};