/*
approach is:
Create a copy of every node while traversing the original linked list and maintain a mapping from each original node to its corresponding copied node.
Traverse the list again and use the mapping to connect the next pointers of all copied nodes.
Use the same mapping to assign the random pointers of the copied nodes so that each points to the correct copied node.
Return the copied head, resulting in a deep copy of the original linked list with all next and random relationships preserved.
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insert(Node* head){
        Node* temp = head;
        while(temp != NULL){
            Node* nextEl = temp->next;
            Node* copy = new Node(temp->val);
            temp->next = copy;
            copy->next = nextEl;
            temp = nextEl;
        }
    }

    void connectRandom(Node* head){
        Node* temp = head;
        while(temp != NULL){
            Node* copy = temp->next;
            if(temp->random != NULL){
                copy->random = temp->random->next;
            } else {
                copy->random = NULL;
            }
            temp = temp->next->next;
        }
    }
    
    Node* deepCopy(Node* head){
        Node* temp = head;
        Node* dummy = new Node(0);
        Node* res = dummy;

        while(temp != NULL){
            Node* copy = temp->next;
            res->next = copy;
            res = res->next;
            temp->next = copy->next;
            temp = temp->next;
        }
        return dummy->next;
    }

    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return NULL;
        }
        insert(head);
        connectRandom(head);
        return deepCopy(head);
    }
};
