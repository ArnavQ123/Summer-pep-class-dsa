/* Binary Tree Node Structure
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/
class Solution {
  public:
    void findLeaves(Node* root, int level, vector<int>& leaves) {
        if (root == nullptr)
            return;

        if (root->left == nullptr && root->right == nullptr) {
            leaves.push_back(level);
            return;
        }

        findLeaves(root->left, level + 1, leaves);
        findLeaves(root->right, level + 1, leaves);
    }

    int getCount(Node *root, int k) {
        vector<int> leaves;
        findLeaves(root, 1, leaves);

        sort(leaves.begin(), leaves.end());

        int count = 0;

        for (int cost : leaves) {
            if (k < cost)
                break;

            k -= cost;
            count++;
        }

        return count;
    }
};



