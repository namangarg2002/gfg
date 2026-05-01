/*
class Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}; */

class Solution {
  public:
    int getLength(Node* &head){
        if(head == NULL) return 0;
        Node* temp = head;
        int count = 0;
        while(temp != NULL){
            temp = temp->next;
            count++;
        }
        return count;
    }
    int getMiddle(Node* head) {
        if(head->next == NULL) return head->data;
    
        int length = getLength(head);
        int middleIndex = length/2;
        Node* prev = NULL;
        Node* curr = head;
        int currNodeIndex = 0;
        while(currNodeIndex < middleIndex){
            prev = curr;
            curr = curr->next;
            currNodeIndex++;
        }
    
        return curr->data;
            
    }
};