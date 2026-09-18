/* Binary Tree Node Structure
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; 
*/

class Solution {
    int ans;
    int prev;

    void inorder(Node* root) {
        if (root == NULL)
            return;

        inorder(root->left);

        if (prev != -1)
            ans = min(ans, root->data - prev);

        prev = root->data;

        inorder(root->right);
    }

public:
    int absDiff(Node* root) {
        ans = INT_MAX;
        prev = -1;

        inorder(root);

        return ans;
    }
};

