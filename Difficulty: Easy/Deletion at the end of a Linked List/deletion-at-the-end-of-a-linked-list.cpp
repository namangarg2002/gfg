/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node* removeLastNode(Node* head) {
        
        if(head == NULL) return NULL;
        if(head->next == NULL) return NULL;
        
        Node* prev = NULL;
        Node* curr = head;
        while(curr->next != NULL){
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
        delete curr;
        return head;
        
    }
};