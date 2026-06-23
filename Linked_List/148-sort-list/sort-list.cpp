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
    ListNode* midNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
    
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* trav = dummyHead;

        while(head1 != NULL && head2 != NULL) {
            if(head1->val > head2->val) {
                trav->next = head2;
                head2 = head2->next;
            } else {
                trav->next = head1;
                head1 = head1->next;
            }

            trav = trav->next;
        }

        if(head1 != NULL)
            trav->next = head1;
        else
            trav->next = head2;
        
        return dummyHead->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* mid = midNode(head);
        ListNode* head2 = mid->next;
        mid->next = NULL;

        ListNode* left = sortList(head);
        ListNode* right = sortList(head2);

        return merge(left, right);
    }
};