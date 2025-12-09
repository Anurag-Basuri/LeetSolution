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
int getlen(ListNode * head){
    
    int cnt=0;
    ListNode * temp=head;
    while(temp!=NULL){
        cnt++;
        temp=temp->next;
    }
    return cnt;
}
    ListNode* swapPairs(ListNode* head) {
        
    if(head==NULL){
        return NULL;
    }
    ListNode * next=NULL;
    ListNode * prev=NULL;
    ListNode * curr=head;
    int count=0;
    int k=2;
        while(curr!=NULL&&count<k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        if(next!=NULL){
            if(getlen(next)>=k){
            head->next= swapPairs(next);
        }
        else{
            head->next=next;
        }
        }
        return prev;
    }
};