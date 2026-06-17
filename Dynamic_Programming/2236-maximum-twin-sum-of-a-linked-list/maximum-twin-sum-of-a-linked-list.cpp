class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* prev = NULL;
        ListNode* fast = head;
        
        while (fast != NULL && fast->next != NULL) {
            ListNode* nextSlow = slow->next;
            ListNode* nextFast = fast->next->next;
            
            slow->next = prev;
            prev = slow;
            
            slow = nextSlow;
            fast = nextFast;
        }
        
        ListNode* firstHalf = prev;
        ListNode* secondHalf = slow;
        int maxSum = 0;
        
        while (firstHalf != NULL) {
            int sum = firstHalf->val + secondHalf->val;
            maxSum = max(maxSum, sum);
            
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        
        return maxSum;
    }
};