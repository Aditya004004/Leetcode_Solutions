/*
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
    Node* copyRandomList(Node* head) {

        if (head == nullptr)
            return nullptr;

        Node* temp = head;

        while (temp != nullptr) {

            Node* copyNode = new Node(temp->val);

            copyNode->next = temp->next;
            temp->next = copyNode;

            temp = copyNode->next;
        }

        temp = head;

        while (temp != nullptr) {

            Node* copyNode = temp->next;

            if (temp->random != nullptr) {
                copyNode->random = temp->random->next;
            }

            temp = temp->next->next;
        }

        temp = head;

        Node* copyHead = head->next;
        Node* copyTemp = copyHead;

        while (temp != nullptr) {

            temp->next = temp->next->next;

            if (copyTemp->next != nullptr) {
                copyTemp->next = copyTemp->next->next;
            }

            temp = temp->next;
            copyTemp = copyTemp->next;
        }

        return copyHead;
    }
};