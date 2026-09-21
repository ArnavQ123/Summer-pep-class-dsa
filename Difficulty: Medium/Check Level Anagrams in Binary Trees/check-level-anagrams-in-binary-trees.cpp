/* Structure of binary tree Node
class Node {
    public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/
class Solution {
public:
    bool areAnagrams(Node* a, Node* b) {
        queue<Node*> q1, q2;
        q1.push(a);
        q2.push(b);

        while (!q1.empty() && !q2.empty()) {
            int n = q1.size(), m = q2.size();
            if (n != m) return false;

            vector<int> x, y;

            while (n--) {
                auto p = q1.front(); q1.pop();
                x.push_back(p->data);
                if (p->left) q1.push(p->left);
                if (p->right) q1.push(p->right);
            }

            while (m--) {
                auto p = q2.front(); q2.pop();
                y.push_back(p->data);
                if (p->left) q2.push(p->left);
                if (p->right) q2.push(p->right);
            }

            sort(x.begin(), x.end());
            sort(y.begin(), y.end());

            if (x != y) return false;
        }

        return q1.empty() && q2.empty();
    }
};