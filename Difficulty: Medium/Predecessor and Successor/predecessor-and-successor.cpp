/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* pre = NULL;
        Node* suc = NULL;

        while (root) {
            if (key < root->data) {
                suc = root;
                root = root->left;
            }
            else if (key > root->data) {
                pre = root;
                root = root->right;
            }
            else {
                if (root->left) {
                    Node* temp = root->left;
                    while (temp->right)
                        temp = temp->right;
                    pre = temp;
                }

                if (root->right) {
                    Node* temp = root->right;
                    while (temp->left)
                        temp = temp->left;
                    suc = temp;
                }

                break;
            }
        }

        return {pre, suc};
    }
};