/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return NULL;

        Node* head = root;

        while(head){
            Node* temp = new Node();
            Node* cur = temp;

            while(head){
                if(head->left){
                    cur->next = head->left;
                    cur = cur->next;
                }

                if(head->right){
                    cur->next = head->right;
                    cur = cur->next;
                }

                head = head->next;
            }

            head = temp->next;
        }

        return root;
    }
};