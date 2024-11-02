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
        if (root == nullptr) {
            return nullptr;
        }

        queue<Node*> temp;
        temp.push(root);

        while (!temp.empty()) {
            vector<Node*> lv_node;
            int size = temp.size();

            for (int i = 0; i < size; i++) {
                Node* x = temp.front();
                temp.pop();
                lv_node.push_back(x);

                if (x->left) {
                    temp.push(x->left);
                }
                if (x->right) {
                    temp.push(x->right);
                }
            }

            for (int i = 1; i < size; i++) {
                lv_node[i - 1]->next = lv_node[i];
            }
            lv_node[size - 1]->next = nullptr;
        }

        return root;
    }
};